from django.shortcuts import redirect, render


def index(request):
    dest = request.GET['dest']
    return redirect(dest)  # @violation


def redirect_url(request):
    url_string = request.POST.get('url', '')
    # 사용자 입력에 포함된 URL 주소로 리다이렉트 하는 경우
    # 피싱 사이트로 접속되는 등 사용자가 피싱 공격에 노출될 수 있다
    return redirect(url_string)  # @violation


ALLOW_URL_LIST = [
    '127.0.0.1',
    '192.168.0.1',
    '192.168.0.100',
    'https://login.myservice.com',
    '/notice'
]


def redirect_url(request):
    url_string = request.POST.get('url', '')

    # 이동할 수 있는 URL 범위를 제한하여
    # 위험한 사이트의 접근을 차단하고 있다
    if url_string not in ALLOW_URL_LIST:
        return render(request, '/error.html', {'ERROR': '허용되지 않는 주소입니다.'})

    return redirect(url_string)  # safe
