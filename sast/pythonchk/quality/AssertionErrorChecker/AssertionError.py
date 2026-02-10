def a(n):
    return n * 2

def test_a():
    assert a(2) == 5

test_a()   # @violation



def b(n):
    return n % 2 == 0
def test_b(n):
    assert b(n) % 2 == 1, "it's not an even number"
test_b(4)
test_b(5)   # @violation
