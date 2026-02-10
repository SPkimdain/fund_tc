import os
import subprocess
from subprocess import run
from django.shortcuts import render


def test2(cmd):
    home = os.getenv('APPHOME')
    cmd = home + cmd
    os.system(cmd)  # @violation
    os.system(cmd)  # @violation


def execute_command(request):
    app_name_string = request.POST.get('app_name', '')
    # 입력받은 파라미터를 제한하지 않아 외부 입력값으로 전달된
    # 모든 프로그램이 실행될 수 있음
    os.system(app_name_string)  # @violation
    return render(request, '/success.html')


ALLOW_PROGRAM = ['notepad', 'calc']


def execute_command(request):
    app_name_string = request.POST.get('app_name', '')
    # 입력받은 파라미터를 사용가능한 시스템 명령어 일부로 제한하여 사용
    if app_name_string not in ALLOW_PROGRAM:
        return render(request, '/error.html', {'ERROR': '허용되지 않은 프로그램입니다.'})
    os.system(app_name_string)  # safe
    return render(request, '/success.html')


def execute_command(request):
    date = request.POST.get('date', '')
    # 입력받은 파라미터를 제한하지 않아 전달된 모든 프로그램이
    # 실행될 수 있음
    cmd_str = "cmd /c backuplog.bat " + date
    subprocess.run(cmd_str)  # @violation
    return render(request, '/success.html')


def execute_command(request):
    date = request.POST.get('date', '')
    # 입력받은 파라미터를 제한하지 않아 전달된 모든 프로그램이
    # 실행될 수 있음
    cmd_str = "cmd /c backuplog.bat " + date
    subprocess.run(cmd_str, shell=True) # @violation
    return render(request, '/success.html')


def execute_command(request):
    date = request.POST.get('date', '')

    # 명령어를 추가로 실행 또는 다른 명령이 실행될 수 있는 키워드에
    # 대한 예외처리
    for word in ['|', ';', '&', ':', '>', '<', '`', '\\', '!']:
        date = date.replace(word, "")

        # shell=True 옵션은 제거 하고 명령과 인자를 배열로 입력
        subprocess.run(["cmd", "/c", "backuplog.bat", date])  # safe
        return render(request, '/success.html')


def execute_command(request):
    date = request.POST.get('date', '')

    for word in ['|', ';', '&', ':', '>', '<', '`', '\\', '!']:
        date = date.replace(word, "")

        # shell=True 옵션이 있는 상태
        run(["cmd", "/c", "backuplog.bat", date], shell=True)  # @violation
        return render(request, '/success.html')