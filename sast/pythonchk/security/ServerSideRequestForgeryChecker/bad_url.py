from flask import request
from urllib.request import urlopen
from django.shortcuts import render
import requests


def index(request):
    url = request.GET['url']
    return urlopen(url)  # @violation


@app.route('/proxy')
def proxy():
    url = request.args["url"]
    return urlopen(url).read()  # @violation


def call_third_party_api(request):
    addr = request.POST.get('address', '')

    # 사용자가 입력한 주소를 검증하지 않고 HTTP 요청을 보내고 응답을
    # 사용자에게 반환
    result = requests.get(addr).text  # @violation
    return render(request, '/result.html', {'result': result})


# 도메인을 화이트리스트에 정의 할 경우 DNS rebinding 공격 등에
# 노출될 위험이 있어 신뢰 할 수 있는 자원에 대한 IP를 사용하여
# 검증하는 것이 좀더 안전하다.
ALLOW_SERVER_LIST = [
    'https://127.0.0.1/latest/',
    'https://192.168.0.1/user_data',
    'https://192.168.0.100/v1/public'
]

def call_third_party_api(request):
    addr = request.POST.get('address', '')

    # 사용자가 입력한 URL을 화이트리스트로 검증한 후 그 결과를 반환하여
    # 검증되지 않은 주소로 요청을 보내지 않도록 제한한다.
    if addr not in ALLOW_SERVER_LIST:
        return render(request, '/error.html', {"error" : '허용되지 않은 서버입니다.'})

    result = requests.get(addr).text
    return render(request, '/result.html', {'result': result})
