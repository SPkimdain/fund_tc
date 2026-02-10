from ldap3 import Server, Connection, ALL


def simple_bind():
    s = Server('servername', get_info=ALL)
    c = Connection(s, user='user_dn', password='user_password')
    if not c.bind():
        print('error in bind', c.result)


def simple_bind2():
    s = Server('servername', get_info=ALL)
    c = Connection(s, password='user_password', user='user_dn')
    if not c.bind():
        print('error in bind', c.result)


def simple_bind_unauthenticated():
    s = Server('servername', get_info=ALL)
    c = Connection(s, user='user_dn')  # @violation
    if not c.bind():
        print('error in bind', c.result)


def anonym_bind():
    s = Server('servername', get_info=ALL)
    c = Connection(s)  # @violation
    if not c.bind():
        print('error in bind', c.result)


def anonym_bind2():
    s = Server(host='servername', port=389, use_ssl=False, get_info=ALL)
    c = Connection(s, user='', password='', auto_bind='NONE', version=3, authentication='ANONYMOUS')  # @violation
    if not c.bind():
        print('error in bind', c.result)