import os.path
import io
import datetime
import threading

def write(filename, content):
    # 멀티스레드 환경에서만 위험하다고 간주함으로 안전
    if os.path.isfile(filename) is True:
        f = open(filename, 'w')             # safe
        f.seek(0, io.SEEK_END)
        f.write(content)
        f.close()

def write_shared_file(filename, content):
    # 멀티스레드 환경에서는 다른 사용자들의 작업에 따라 파일이 사라질
    # 수 있기 때문에 공유 자원에 대해서는 검사와 사용을 동시에 해야 한다.
    if os.path.isfile(filename) is True:
        f = open(filename, 'w')             # @violation
        f.seek(0, io.SEEK_END)
        f.write(content)
        f.close()

def start():
    filename = './temp.txt'
    content = 'start time is ' + datetime.datetime.now()
    my_thread = threading.Thread(target=write_shared_file, args=(filename, content))
    my_thread.start()
