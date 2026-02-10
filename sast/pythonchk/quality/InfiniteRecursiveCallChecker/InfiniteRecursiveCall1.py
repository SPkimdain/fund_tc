def infinite_recursive_call_1(n):                   # @violation
    return infinite_recursive_call_1(n-1)           # if statement X

def infinite_recursive_call_2(n):                   # @violation
    if n > 0:
        return infinite_recursive_call_2(n-1)       # all if statement have recursive call
    else:
        return infinite_recursive_call_2(n+1)

def infinite_recursive_call_3(n):                   # @violation
    if n > 0:
        return infinite_recursive_call_3(n-1)
    return infinite_recursive_call_3(n+1)

def infinite_recursive_call_4(n):                   # good
    if n > 0:
        return infinite_recursive_call_4(n-1)
    return 1

def infinite_recursive_call_5(n):                   # good
    if n < 0:
        return 1
    return infinite_recursive_call_5(n-1)

def infinite_recursive_call_6(n):                   # good
    if n < 0:
        return 1
    elif n < -2:
        return infinite_recursive_call_6(n-1)
    return infinite_recursive_call_6(n-1)

def infinite_recursive_call_7(n):                   # good
    if n < 0:
        return 1
    else:
        return infinite_recursive_call_7(n-1)

def infinite_recursive_call_8(n):                   # good
    if n < 0:
        return 1
    elif n < -2:
        return infinite_recursive_call_8(n-1)

def infinite_recursive_call_9(n):                  # good
    if n < 0:
        return infinite_recursive_call_9(n-1)
    elif n < -2:
        return infinite_recursive_call_9(n-1)

    return 1

def infinite_recursive_call_10(n):                  # good
    i = None
    if n > 0:
        i = infinite_recursive_call_10(n-1)
    else:
        i = 1

    return i

def infinite_recursive_call_11(n):                  # good
    def infinite_recursive_call_11_1(n):
        if n > 0:
            return infinite_recursive_call_11_1(n-1)
        else:
            return 1

    infinite_recursive_call_11_1(n-1)

def infinite_recursive_call_12(n):                  # @violation
    def infinite_recursive_call_12_1(n):
        if n > 0:
            return infinite_recursive_call_12(n-1)
        else:
            return infinite_recursive_call_12(n+1)

    infinite_recursive_call_12_1(n-1)

def infinite_recursive_call_13(n):                  # @violation
    def infinite_recursive_call_13_1(n):
        if n > 0:
            return infinite_recursive_call_13(n-1)
        else:
            return infinite_recursive_call_13_1(n+1)

    infinite_recursive_call_13_1(n-1)

def infinite_recursive_call_14(n):
    def infinite_recursive_call_14_1(n):            # @violation
        def infinite_recursive_call_14_2(n):
            if n > 0:
                return infinite_recursive_call_14_1(n-1)
            else:
                return infinite_recursive_call_14_2(n+1)

        infinite_recursive_call_14_2(n-1)
    infinite_recursive_call_14_1(n)

def infinite_recursive_call_15(x):                  # @violation
    return infinite_recursive_call_15(x - 1) + infinite_recursive_call_15(x - 2)

def infinite_recursive_call_16(x):                  # @violation
    if x <= 1:
        return infinite_recursive_call_16(x - 3)
    else:
        return infinite_recursive_call_16(x - 1) + infinite_recursive_call_16(x - 2)

def infinite_recursive_call_17(x):                  # good
    if x <= 1:
        return 1
    else:
        return infinite_recursive_call_17(x - 1) + infinite_recursive_call_17(x - 2)
