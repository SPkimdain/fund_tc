import ssl
import requests
from OpenSSL import SSL

def violation1():
    requests.request('GET', 'https://example.com', verify=False)                    # @violation
    requests.get('https://example.com', verify=False)                               # @violation

def violation2():
    ctx1 = ssl._create_unverified_context()                                         # @violation
    ctx2 = ssl._create_stdlib_context()                                             # @violation

    ctx3 = ssl.create_default_context()
    ctx3.verify_mode = ssl.CERT_NONE                                                # @violation

def violation3():
    ctx1 = SSL.Context(SSL.TLSv1_2_METHOD)                                          # @violation

    ctx2 = SSL.Context(SSL.TLSv1_2_METHOD)                                          # @violation
    ctx2.set_verify(SSL.VERIFY_NONE, verify_callback)

def good1():
    requests.request('GET', 'https://example.com', verify=True)                     # good
    requests.request('GET', 'https://example.com', verify='/path/to/CAbundle')      # good
    requests.get(url='https://example.com')                                         # good

def good2():
    ctx = ssl.create_default_context()
    ctx.verify_mode = ssl.CERT_REQUIRED                                             # good

    ctx = ssl._create_default_https_context()                                       # good

def good3():
    ctx = SSL.Context(SSL.TLSv1_2_METHOD)                                           # good
    ctx.set_verify(SSL.VERIFY_PEER, verify_callback)
    ctx.set_verify(SSL.VERIFY_PEER | SSL.VERIFY_FAIL_IF_NO_PEER_CERT, verify_callback)
    ctx.set_verify(SSL.VERIFY_PEER | SSL.VERIFY_FAIL_IF_NO_PEER_CERT | SSL.VERIFY_CLIENT_ONCE, verify_callback)