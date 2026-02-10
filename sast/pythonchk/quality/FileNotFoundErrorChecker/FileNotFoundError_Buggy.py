def buggy_open_file():
    filename = "nothing.txt"
    # BUG, FileNotFoundError
    f = open(filename)                # @violation
    f.close()

buggy_open_file()