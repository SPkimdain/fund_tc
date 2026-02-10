from hashlib import sha256
from Crypto.Hash import SHA256


def bad_store(request):
    username = request.GET["username"]
    password = request.GET["password"]
    with socket.socket() as s:
        s.bind(('some.host.url.com', 9876))
        s.send(bytes(username, encoding='utf-8'))
        s.send(bytes(password, encoding='utf-8'))  # @violation
        s.sendall(bytes(password, encoding='utf-8'))  # @violation


def safe_store(request):
    username = request.GET["username"]
    password = request.GET["password"]
    with socket.socket() as s:
        s.bind(('some.host.url.com', 9876))
        s.sendall(bytes(username, encoding='utf-8'))
        h = SHA256.new(bytes(password, encoding='utf-8'))
        s.sendall(h.digest())  # safe


def safe_store2(request):
    username = request.GET["username"]
    password = request.GET["password"]
    with socket.socket() as s:
        s.bind(('some.host.url.com', 9876))
        s.sendall(bytes(username, encoding='utf-8'))
        h = sha256()
        h.update(bytes(password, encoding='utf-8'))
        s.sendall(h.digest())  # safe

