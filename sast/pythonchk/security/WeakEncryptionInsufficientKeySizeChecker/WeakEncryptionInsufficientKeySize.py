from Crypto.PublicKey import RSA
from Crypto import Random
from Crypto.PublicKey import RSA, DSA, ECC
from tinyec import registry
import secrets

def weak_encryption_insufficient_key_size_1():
    random_generator = Random.new().read
    key = RSA.generate(1024, random_generator)                              # @violation
    print(key)

def weak_encryption_insufficient_key_size_2():
    random_generator = Random.new().read
    key = RSA.generate(1023+1024, random_generator)                         # @violation
    print(key)

def weak_encryption_insufficient_key_size_3():
    keySize1 = 1023
    keySize2 = 512
    keySize3 = 2
    random_generator = Random.new().read
    key = RSA.generate(keySize1 +keySize2* keySize3 , random_generator)     # @violation
    print(key)

def weak_encryption_insufficient_key_size_4():
    keySize1 = 1024
    keySize2 = 1024
    random_generator = Random.new().read
    key = RSA.generate(keySize1+keySize2, random_generator)                 # good
    print(key)

def make_rsa_key_pair():
    # RSA키 길이를 1024 비트로 설정하는 경우 안전하지 않음
    private_key = RSA.generate(1024)                                        # @violation
    public_key = private_key.publickey()

def make_ecc():
    # 2015년부터 ECC 키 길이를 256 비트 이상으로 제안하고 있음.
    ecc_curve = registry.get_curve('secp192r1')                             # @violation
    private_key = secrets.randbelow(ecc_curve.field.n)
    public_key = private_key * ecc_curve.g

def make_rsa_key_pair():
    # RSA키 길이를 2048 비트 이상으로 길게 설정
    private_key = RSA.generate(2048)                                        # good
    public_key = private_key.publickey()

def make_ecc():
    # ECC 키 길이를 256 비트 이상으로 설정.
    ecc_curve = registry.get_curve('secp256r1')                             # good
    private_key = secrets.randbelow(ecc_curve.field.n)
    public_key = private_key * ecc_curve.g

def violation():
    ECC.generate(curve='p256')                                              # good
    ECC.generate(curve='NIST P-192')                                        # @violation
    ECC.generate('P-192')                                                   # @violation
    ECC.generate('prime192v1')                                              # @violation
    ECC.generate('secp192r1')                                               # @violation
    ECC.generate('NIST P-224')                                              # @violation
    ECC.generate('p224')                                                    # @violation
    ECC.generate('P-224')                                                   # @violation
    ECC.generate('prime224v1')                                              # @violation
    ECC.generate('secp224r1')                                               # @violation
    registry.get_curve('brainpoolP160r1')                                   # @violation
    registry.get_curve('brainpoolP192r1')                                   # @violation
    registry.get_curve('brainpoolP224r1')                                   # @violation
    registry.get_curve('secp192r1')                                         # @violation
    registry.get_curve('secp224r1')                                         # @violation
