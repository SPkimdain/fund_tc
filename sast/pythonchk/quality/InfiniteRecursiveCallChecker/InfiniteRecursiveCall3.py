def factorial(num):                                 # @violation
    # 재귀함수 탈출조건을 설정하지 않아 동작 중 에러 발생
    return num * factorial(num - 1)

if __name__ == '__main__':
    itr = 5
    result = factorial(itr)
    print(str(itr) + ' 팩토리얼 값은 : ' + str(result))
