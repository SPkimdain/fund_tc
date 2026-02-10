from flask import request
from django.shortcuts import render

@app.route('/')
def index():
    module = request.args.get("module")
    exec("import urllib%s as urllib" % module)      # @violation


def index():
    module = request.args.get("module")
    exec "import urllib%s as urllib" % module      # @violation


def route(request):
    #외부로 입력받은 값을 검증 없이 사용하면 안전하지 않다.
    message = request.POST.get('message', '')

    # eval함수에 외부 입력값을 검증 없이 사용할 경우 Python 코드가
    # 실행될 수 있어 위험하다.

    ret = eval(message)     # @violation
    return render(request, '/success.html', {'data':ret})

def route_good(request):
    message = request.POST.get('message', '')

    # 사용자 입력을 영문, 숫자로 제한하는 예로. 특수문자가 포함되어
    # 있을 경우 에러 메시지를 리턴 한다.
    if message.isalnum():
        ret = eval(message)
        return render(request, '/success.html', {'data':ret})



def request_rest_api(request):
    function_name = request.POST.get('function_name', '')

    # 사용자에게 전달받은 함수명을 검증하지 않고 실행
    # 입력 값으로 “import plaform \n platform.system()” 등을 입력 시
    # 시스템정보 노출 위험이 있다.
    ret = exec('{}()'.format(function_name))    # @violation
    return render(request, '/success', {'data':ret})

WHITE_LIST = ['get_friends_list', 'get_address', 'get_phone_number']

def request_rest_api_good(request):
    function_name = request.POST.get('function_name', '')

    # 함수 명을 화이트리스트로 제한
    if function_name in WHITE_LIST:
        ret = exec('{}()'.format(function_name))
        return render(request, '/success', {'data':ret})
    return render(request, '/error', {'error':'허용되지 않은 함수입니다.'})