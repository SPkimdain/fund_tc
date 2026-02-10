#Unicode Error
def decode_error():
    b'\x80abc'.decode("utf-8", "strict") # @violation


def encode_error():
    u = chr(40960) + 'abcd' + chr(1972)
    u.encode('ascii')                       # @violation

decode_error()
encode_error()