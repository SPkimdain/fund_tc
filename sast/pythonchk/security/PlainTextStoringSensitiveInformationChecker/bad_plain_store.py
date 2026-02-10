from hashlib import sha256
from Crypto.Hash import SHA256


def bad_store(request):
    filename = "a.txt"
    username = request.GET["username"]
    password = request.GET["password"]
    with open(filename) as f:
        f.write(username)
        f.write(password)  # @violation


def safe_store(request):
    filename = "a.txt"
    username = request.GET["username"]
    password = request.GET["password"]
    with open(filename) as f:
        f.write(username)
        h = SHA256.new(bytes(password, encoding='utf-8'))
        f.write(h.digest())  # safe


def safe_store2(request):
    filename = "a.txt"
    username = request.GET["username"]
    password = request.GET["password"]
    with open(filename) as f:
        f.write(username)
        h = sha256()
        h.update(bytes(password, encoding='utf-8'))
        f.write(h.digest())  # safe
