import os
import crypt
import hashlib
from hashlib import pbkdf2_hmac
import secrets

iter_count = 100
salt = b''
password = b'password'
salt2 = b'asdasd'

dk = pbkdf2_hmac('sha256', password, b'', 100000)  # @violation
pbkdf2_hmac('sha256', password, salt, 100000)  # @violation
pbkdf2_hmac('sha256', password, salt=b'', iterations=iter_count)  # @violation
pbkdf2_hmac('sha256', password, b'!@#$%^', iterations=iter_count)
pbkdf2_hmac('sha256', password, b'abcdefg', iterations=iter_count)
pbkdf2_hmac('sha256', password, salt2, iterations=iter_count)

def get_hash_from_pwd_1(pw):
    # salt가 없이 생성된 해시값은 강도가 약하기 때문에 반드시 salt와 함께
    # 생성해야 한다.
    h = hashlib.sha256(pw.encode()) # @violation

    return h.digest()

def get_hash_from_pwd_2(pw):
    # 비밀번호와 같이 길이가 짧은 값을 이용하여
    # 고강도의 해시를 생성하기 위해서는 salt값을
    # 사용하면 강도높은 해시를 생성할 수 있다
    salt = secrets.token_hex(32)
    h = hashlib.sha256(salt.encode() + pw.encode()) # good

    return h.digest(), salt

def get_hash_from_pwd_3(pw):
    salt = os.urandom(32)
    h = hashlib.sha256(salt + pw.encode()) # good

    return h.digest(), salt

def get_hash_from_pwd_4(pw):
    salt = crypt.mksalt().encode()
    h = hashlib.sha256(salt + pw.encode()) # good

    return h.digest(), salt


def SWPY3123(request):
    if request.method == 'POST':
        tmp = request.POST.get('content')
        tmp1 = os.urandom(32) + request.POST.get('content').encode()
        tmp2 = request.POST.get('content').encode()
        tmp3 = (tmp + secrets.token_hex(0)).encode()
        tmp4 = (tmp + tmp).encode()

        test1 = hashlib.sha256()  # @violation
        test2 = hashlib.sha256(tmp1)
        test3 = hashlib.sha256(tmp.encode())   # @violation
        test4 = hashlib.sha256(tmp.encode() + secrets.token_hex(32).encode())
        test5 = hashlib.sha256(secrets.token_hex(32).encode() + tmp.encode())
        test6 = hashlib.sha256(tmp2)   # @violation
        test7 = hashlib.sha256(tmp3)   # @violation
        test8 = hashlib.sha256(tmp4)   # @violation
        data = {
            'data': "success"
        }
        return JsonResponse(data)