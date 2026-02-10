def countdown(n):
    while n> 10:
        yield n
        n -= 1
    return n


for x in countdown(13):
    print(x)

c = countdown(13)
next(c)
next(c)
next(c)
next(c)   # @violation