# -*- coding: utf-8 -*-


def myfunction(b):  # @violation # comment 1: password: abcde0aaa8aaa9baaaaab0bbd!aaa1
    pass
    pass  # comment 2
    pass
    if b:  # comment 3 - longpatternabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqr
        pass
    else:
        while b:  # comment 4 비밀번호 abcde0aaa8aaa9baaaaab0bbd!aaa1 이다
            pass
    print('# x')  # comment 5 long fixed ABCDEFGHIJ0123456789ABCDEFGHIJ0123456789


class MyClass(obj):  # comment 6
    def tostr(self):  # comment 7
        pass
        return """# test"""  # comment 8

def user_login_1(id, passwd):
    # 주석문에 포함된 중요 시스템의 인증 정보
    # id = admin
    # @violation # passwd = passw0rd
    result = login(id, passwd)

    return result

def user_login_2(id, passwd):
    # 주석문에 포함된 민감한 정보는 삭제
    result = login(id, passwd)
    return result

# https://docs.djangoproject.com/en/4.1/ref/settings/#auth-password-validators
# @violation pw =
# @violation pw :
# @violation pw,