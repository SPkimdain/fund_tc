from django.http import HttpResponse


def index(request):
    user_id = request.GET['id']
    response = HttpResponse('OK')
    response.set_cookie('id', user_id)  # @violation 3
    response.set_cookie('id', user_id, max_age=360000)  # @violation 3
    return response


def index_safe(request):
    user_id = request.GET['id']
    response = HttpResponse('OK')
    if '\N{LINE FEED}' not in user_id:
        response.set_cookie('id', user_id, max_age=3600, secure=True, httponly=True)  # safe
    else:
        pass
    return response

def remind_user_state_1(request):
    res = HttpResponse()
    # 쿠키의 만료시간을 1년으로 과도하게 길게 설정하고 있어 안전하지 않다.
    res.set_cookie('rememberme', 1, max_age=60*60*24*365)   # @violation 3
    return res

def remind_user_state_2(request):
    res = HttpResponse()
    #쿠키의 만료시간을 적절하게 부여하고 secure 옵션을 활성화 한다.
    res.set_cookie('rememberme', 1, max_age=60*60, secure=True, httponly=True)  # good
    return res