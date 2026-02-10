import urllib
from urllib.request import Request


def download(url):
    # BUG, TimeoutError
    request = urllib.request.urlopen(url, timeout=60)           # @violation
    data = request.read()
    decoded = data.decode('utf-8')
    return decoded

