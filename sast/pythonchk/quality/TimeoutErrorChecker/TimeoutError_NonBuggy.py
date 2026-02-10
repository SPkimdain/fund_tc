import urllib
from urllib.request import Request


def download(url):
    try:
        request = urllib.request.urlopen(url, timeout = 60)
        data = request.read()
        decoded = data.decode('utf-8')
    except TimeoutError:
        print("Timeout Error")
    return decoded