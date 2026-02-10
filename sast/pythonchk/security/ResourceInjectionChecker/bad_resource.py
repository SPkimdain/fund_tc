import os
import socket
from django.shortcuts import render


def bad_os(request):
    name = request.GET['name']
    file = os.open(name)  # @violation


def bad_builtin(request):
    name = request.field('name')
    file = open(name)  # @violation


def bad_sock(request):
    name = request.GET['id']
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((name, 8000))  # @violation


def get_info(request):
    # 외부로부터 파일명을 입력받고 있다.
    request_file = request.POST.get('request_file')
    filename, file_ext = os.path.splitext(request_file)
    file_ext = file_ext.lower()

    if file_ext not in ['.txt', '.csv']:
        return render(request, '/error.html', {'error': '파일을 열수 없습니다.'})

    # 외부로부터 입력받은 값을 검증 없이 파일 처리에 사용하였다.
    with open(request_file) as f:   # @violation
        data = f.read()

    return render(request, '/success.html', {'data': data})


def get_info(request):
    # 외부 입력 값으로 받은 파일 이름은 검증하여 사용한다.
    request_file = request.POST.get('request_file')

    filename, file_ext = os.path.splitext(request_file)
    file_ext = file_ext.lower()

    if file_ext not in ['.txt', '.csv']:
        return render(request, '/error.html', {'error': '파일을 열수 없습니다.'})

    # 파일 명에서 경로 조작 문자열을 필터링 한다.
    filename = filename.replace('.', '')
    filename = filename.replace('/', '')
    filename = filename.replace('\\', '')

    with open(filename + file_ext) as f:   # safe
        data = f.read()

    return render(request, '/success.html', {'data': data})


def get_info(request):
    port = request.POST.get('port')

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        # 외부로부터 입력받은 검증되지 않은 포트번호를 이용하여
        # 소켓을 바인딩 하여 사용하고 있어 안전하지 않다.
        s.bind(('127.0.0.1', port))  # @violation
        return render(request, '/success')
    return render(request, '/error', {'error': '소켓연결 실패'})


ALLOW_PORT = [4000, 6000, 9000]


def get_info(request):
    port = int(request.POST.get('port'))

    # 사용 가능한 포트 번호를 화이트리스트로 제한
    if port not in ALLOW_PORT:
        return render(request, '/error', {'error': '소켓연결 실패'})

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind(('127.0.0.1', port))  # safe
    return render(request, '/success')
