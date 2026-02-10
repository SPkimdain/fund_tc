def buggy_open_file():
    filename = "nothing.txt"
    dir = "temp"
    sep = "/"
    # BUG, UsingFileSeparator
    f = open(dir + sep + filename)              # @violation
    f.close()
    f2 = open(dir + "/" + filename)             # @violation
    f2.close()
    f3 = open(dir + "\\" + filename)            # @violation
    f3.close()

buggy_open_file()