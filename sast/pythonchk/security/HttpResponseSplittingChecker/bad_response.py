from django.http import HttpResponse
from sparrow.my.filter.utils import is_safe


def index_safe_filter(request):
    userId = request.GET['id']
    response = HttpResponse('OK')
    if is_safe(userId):
        response.set_cookie(userId)  # safe with filter function 'my.filter.utils.is_safe'
    else:
        response.set_cookie('dummy')
    return response


def route(request):
    content_type = request.POST.get('contnet-type')
    # 외부 입력값을 검증 또는 필터링 하지 않고
    # 응답헤더의 값으로 포함시켜 회신한다.
    res = HttpResponse()
    res['Content-Type'] = content_type  # @violation
    return res


def route(request):
    content_type = request.POST.get('contnet-type')
    # 응답헤더에 포함될 수 있는 외부 입력값에 대해 개행문자를 제거한다.
    content_type = content_type.replace('\r', '')
    content_type = content_type.replace('\n', '')

    res = HttpResponse()
    res['Content-Type'] = content_type  # safe
    return res
