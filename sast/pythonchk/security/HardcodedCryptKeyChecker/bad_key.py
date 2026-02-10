from Crypto.Cipher import AES, DES


def bad_enc():
    key = b'0123456789'

    cipher_a = AES.new(key)  # @violation
    cipher_text = cipher_a.encrypt(b'Plain Text Message')
    cipher_text += cipher_a.encrypt(b'More Plain Text Message')
    result = cipher_text.nonce

    cipher_b = DES.new(key)  # @violation
    cipher_text = cipher_b.encrypt(b'Plain Text Message')
    cipher_text += cipher_b.encrypt(b'More Plain Text Message')
    result = cipher_text.nonce

    with open('key.dat', 'rt') as f:
        loaded_key = f.readline()
        cipher_a = AES.new(bytes(loaded_key, encoding='utf-8'))  # safe
        cipher_text = cipher_a.encrypt(b'Plain Text Message')
        cipher_text += cipher_a.encrypt(b'More Plain Text Message')
        result = cipher_text.nonce
