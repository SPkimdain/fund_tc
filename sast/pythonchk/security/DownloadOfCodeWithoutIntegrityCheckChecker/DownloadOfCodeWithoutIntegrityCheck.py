import hashlib
import requests
from urllib.request import urlopen
from urllib.request import urlretrieve
from sparrow.my.filter.utils import is_safe
import os
import requests
from urllib.parse import urlparse

def download_of_code_without_integrity_check_1():
    url = "https://upload.wikimedia.org/wikipedia/commons/thumb/9/9c/Dax_sample.png/200px-Dax_sample.png"
    savename = "sample.png"

    resource = urlopen(url)
    data = resource.read()
    f = open(savename, mode="wb")
    f.write(data)                           # @violation
    f.close()

def download_of_code_without_integrity_check_2():
    url = "https://upload.wikimedia.org/wikipedia/commons/thumb/9/9c/Dax_sample.png/200px-Dax_sample.png"
    savename = "sample.png"

    resource = urlopen(url)
    data = resource.read()
    with open(savename, mode="wb") as f:
        f.write(data)                       # @violation

def download_of_code_without_integrity_check_3():
    url = "https://upload.wikimedia.org/wikipedia/commons/thumb/9/9c/Dax_sample.png/200px-Dax_sample.png"
    savename = "sample.png"

    urlretrieve(url, savename)              # @violation

def download_of_code_without_integrity_check_4():
    url = "https://upload.wikimedia.org/wikipedia/commons/thumb/9/9c/Dax_sample.png/200px-Dax_sample.png"
    savename = "sample.png"

    if check_integrity(url):                # good
        resource = urlopen(url)
        data = resource.read()
        f = open(savename, mode="wb")
        f.write(data)
        f.close()

def download_of_code_without_integrity_check_5():
    url = "https://upload.wikimedia.org/wikipedia/commons/thumb/9/9c/Dax_sample.png/200px-Dax_sample.png"
    savename = "sample.png"

    if is_safe():                           # good
        urlretrieve(url, savename)

def check_integrity(url):
    sha256_hash = "9122d50d159fb37c108b02e0dbc5e59cec8404f21c0bb60e3241f80ff5fe35cd"

    resource = urlopen(url)
    data = resource.read()
    hexdigest = hashlib.sha256(data).hexdigest()

    return hexdigest == sha256_hash

def execute_remote_code():
    #신뢰되지 않는 사이트에서 코드를 다운로드
    url = "https://www.somewhere.com/storage/code.py"

    # 원격 코드 다운로드
    file = requests.get(url)
    remote_code = file.content

    file_name = 'save.py'
    with open(file_name, 'wb') as f:
        f.write(file.content)                   # @violation

def execute_remote_code():
    url = "https://www.somewhere.com/storage/code.py"
    remote_code_hash = config.get('HASH', 'file_hash')

    #원격 코드 다운로드
    file = requests.get(url)
    remote_code = file.content
    sha = hashlib.sha256()
    sha.update(remote_code)

    #다운로드 받은 파일의 해시값 검증
    if sha.hexdigest() != remote_code_hash:     # good
        raise Exception('파일이 손상되었습니다.')

        file_name = 'save.py'
        with open(file_name, 'wb') as f:
            f.write(file.content)