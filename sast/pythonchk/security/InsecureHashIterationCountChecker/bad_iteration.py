from hashlib import pbkdf2_hmac

iter_count = 100
password = b'password'

p1 = pbkdf2_hmac('sha256', password, b'', 100000)
pbkdf2_hmac('sha256', password, salt=b'', iterations=iter_count)  # @violation
p3 = pbkdf2_hmac('sha256', password=password, iterations=iter_count, salt=b'')  # @violation
