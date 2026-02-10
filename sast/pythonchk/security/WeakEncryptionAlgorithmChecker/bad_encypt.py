import base64
from hashlib import sha1, sha256, md5
from Crypto.Hash import SHA1, SHA256
import Crypto.Hash.MD5
from Crypto.Cipher import AES, DES, DES3, ARC2, ARC4, Blowfish
import hashlib


def bad_hash():
    hash_object = SHA256.new(data=b'First')
    hash_object.update(b'Second')
    hash_object.update(b'Third')
    hash_object.digest()

    hash_object2 = Crypto.Hash.MD5.new(data=b'First')  # @violation
    hash_object2.update(b'Second')
    hash_object2.update(b'Third')
    hash_object2.digest()

    hash_object3 = SHA1.new(data=b'First')  # @violation
    hash_object3.update(b'Second')
    hash_object3.update(b'Third')
    hash_object3.digest()

    m = sha1()  # @violation
    m.update(b'First')
    m.update(b'Second')
    m.digest()

    m2 = hashlib.new('sha1')  # @violation
    m2.update(b'Repeat')
    m2.digest()

    m3 = hashlib.sha256()
    m3.update(b'Safe')
    m3.digest()


def bad_enc():
    key = b'0123456789'

    cipher_a = AES.new(key)
    cipher_text = cipher_a.encrypt(b'Plain Text Message')
    cipher_text += cipher_a.encrypt(b'More Plain Text Message')
    result = cipher_text.nonce

    cipher_b = DES.new(key)  # @violation
    cipher_text = cipher_b.encrypt(b'Plain Text Message')
    cipher_text += cipher_b.encrypt(b'More Plain Text Message')
    result = cipher_text.nonce

def weak_encryption_insufficient_key_size_5(plain_text, key):
    # 취약함 암호와 알고리즘인 DES를 사용하여 안전하지 않음
    cipher_des = DES.new(key, DES.MODE_ECB)                                 # @violation
    cipher_des3 = DES3.new(key, DES3.MODE_ECB)                              # @violation
    cipher_arc2 = ARC2.new(key, ARC2.MODE_ECB)                              # @violation
    cipher_arc4 = ARC4.new(key, ARC4.MODE_ECB)                              # @violation
    cipher_blow_fish = Blowfish.new(key, Blowfish.MODE_ECB)                 # @violation
    encrypted_data = base64.b64encode(cipher_des.encrypt(plain_text))

    return encrypted_data.decode('ASCII')

def weak_encryption_insufficient_key_size_6(plain_text, key, iv):
    # 안전한 알고리즘인 AES 를 사용하여 안전함.
    cipher_aes = AES.new(key, AES.MODE_CBC, iv)                             # good
    encrypted_data = base64.b64encode(cipher_aes.encrypt(plain_text))

    return encrypted_data.decode('ASCII')

def make_md5(plain_text):
    # 취약한 md5 해쉬함수 사용
    hash_text = hashlib.md5(plain_text.encode('utf-8')).hexdigest()         # @violation

    return hash_text

def make_sha256(plain_text):
    # 안전한 sha-256 해쉬함수 사용
    hash_text = hashlib.sha256(plain_text.encode('utf-8')).hexdigest()      # good

    return hash_text