import requests
from django.shortcuts import render

def reliance_on_untrusted_inputs_in_a_security_decision_1(request):
    DATA={
        'user': request.GET["user"],
        'authenticated': request.GET["authenticated"]
    }

    urlRequest = requests.post('http://google.com', params=DATA)
    urlRequest = requests.post('http://google.com', encoding="utf-8", cookies=DATA)             # @violation
    urlRequest = requests.post('http://google.com', cookies={'user': request.GET["user"]})      # @violation

def reliance_on_untrusted_inputs_in_a_security_decision_2(request):
    DATA={
        'user': request.GET["user"],
        'authenticated': request.GET["authenticated"]
    }

    with requests.Session() as session:
        urlRequest = session.post('http://google.com', DATA)                                    # good

def reliance_on_untrusted_inputs_in_a_security_decision_3(request):
    # 쿠키에서 권한 정보를 가져옴
    roll = request.COOKIE['roll']                                                               # @violation
    request_id = request.POST.get('user_id', '')
    request_mail = request.POST.get('user_email','')
    # 쿠키에서 가져온 권한이 관리자인지 비교
    if roll == 'admin':
        # 사용자의 패스워드 초기화 및 메일 발송 처리
        password_init_and_sendmail(request_id, request_mail)
        return render(request, '/sucess.html')
    else:
        return render(request, '/failed.html')

def reliance_on_untrusted_inputs_in_a_security_decision_4(request):
    # 세션에서 권한 정보를 가져옴
    roll = request.session['roll']                                                              # good
    request_id = request.POST.get('user_id', '')
    request_mail = request.POST.get('user_email','')
    # 세션에서 가져온 권한이 관리자인지 비교
    if roll == 'admin':
        # 사용자의 패스워드 초기화 및 메일 발송 처리
        password_init_and_sendmail(request_id, request_mail)
        return render(request, '/sucess.html')
    else:
        return render(request, '/failed.html')

def SWPY26(request):
    if request.method == "POST":
        roll = request.COOKIES["roll"]  # @violation
        id = request.COOKIES["id"] # @violation
        pwd = request.COOKIES["pwd"] # @violation
        if id == request.POST.get("user_id") and pwd == request.POST.get("msg_format"):
            return JsonResponse({"roll": roll})
        return JsonResponse({"roll": "권한없음"})

    else:
        res = HttpResponse()
        res.set_cookie('key', "test", max_age=60 * 60, httponly=True, secure=True)
        res.set_cookie('roll', "admin", max_age=60 * 60, httponly=True, secure=True)
        res.set_cookie('id', request.GET.get('user_id'), max_age=60 * 60, httponly=True, secure=True)
        res.set_cookie('pwd', request.GET.get('pwd'), max_age=60 * 60, httponly=True, secure=True)
        print(request.GET.get('user_id'))
        print(res)
        return res