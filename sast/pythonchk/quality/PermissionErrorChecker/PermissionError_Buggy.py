def buggy_open_file():
    # assuming that we do not have an access to a.txt
    # BUG, PermissionError

    a_file = open('a.txt', encoding='utf-8')            # @violation
    return a_file


buggy_open_file()
