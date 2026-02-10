import ldap
from ldap3 import Connection, Server, ALL
from django.shortcuts import render


def ldap_query(request):
    # 외부 입력값으로 LDAP 쿼리문의 인자에 검증 없이 사용하면 안전하지 않다.
    search_keyword = request.POST.get('search_keyword','')

    address = 'ldap.badSoruce.com'
    server = Server(address, get_info=ALL)

    dn = server.config['bind_dn']
    password = server.config['password']

    conn = Connection(server, dn, password, auto_bind=True )

    # 사용자 입력을 필터링 하지 않는 경우 공격자의 권한 상승으로 이어질 수 있다
    search_str = '(&(objectclass=%s))' % search_keyword

    conn.search('dc=company,dc=com', search_str, attributes=['sn', 'cn', 'address', 'mail', 'mobile', 'uid']) # @violation
    return render(request, '/ldap_query_response.html', {'ldap':conn.entries})

def ldap_query(request):
    search_keyword = request.POST.get('search_keyword','')

    address = 'ldap.goodsource.com'
    server = Server(address, get_info=ALL)

    dn = server.config['bind_dn']
    password = server.config['password']

    conn = Connection(server, dn, password, auto_bind=True )

    # 사용자의 입력에 필터링을 적용하여 공격에 사용될 수 있는 문자를 이스케이프하고 있다
    escpae_keyword = escape_filter_chars(search_keyword)
    search_str = '(&(objectclass=%s))' % escpae_keyword

    conn.search('dc=company,dc=com', search_str, attributes=['sn', 'cn', 'address', 'mail', 'mobile', 'uid'])
    return render(request, '/ldap_query_response.html', {'ldap':conn.entries})