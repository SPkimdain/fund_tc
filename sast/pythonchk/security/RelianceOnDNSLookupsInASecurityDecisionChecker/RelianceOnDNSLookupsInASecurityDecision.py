import socket

def reliance_on_dns_lookups_in_a_security_decision_1(request):
    ip = request.META.get('REMOTE_ADDR')
    trustedHost = "trustme.com"

    hostname = socket.gethostbyaddr(ip)
    if hostname == trustedHost:             # @violation
        trusted = True

def reliance_on_dns_lookups_in_a_security_decision_2(request):
    ip = request.META.get('REMOTE_ADDR')
    trustedAddr = "127.0.0.1"

    if ip == trustedAddr:                   # good
        trusted = True
