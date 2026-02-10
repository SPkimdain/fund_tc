import sys

sys.setrecursionlimit(1000)                         # good
def factorial(num):                                 # good
    return num * factorial(num - 1)


if __name__ == '__main__':
    itr = 5
    result = factorial(itr)
    print(str(itr) + ' 팩토리얼 값은 : ' + str(result))

