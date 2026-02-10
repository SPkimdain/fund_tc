import os.path
import io
import datetime
import threading

lock = threading.Lock()
def write_shared_file(filename, content):
    # lock을 이용하여 여러 사용자가 동시에 파일에 접근하지 못하도록 제한
    with lock:
        if os.path.isfile(filename) is True:
            f = open(filename, 'w')         # good
            f.seek(0, io.SEEK_END)
            f.write(content)
            f.close()

def start():
    filename = './temp.txt'
    content = 'start time is ' + datetime.datetime.now()
    my_thread = threading.Thread(target=write_shared_file, args=(filename, content))
    my_thread.start()