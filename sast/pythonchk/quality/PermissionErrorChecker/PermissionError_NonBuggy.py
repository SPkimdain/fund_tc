def non_buggy_open_file():
    # assuming that we do not have an access to a.txt
    try:
        a_file = open('a.txt', encoding='utf-8')
    except PermissionError:
        print("permission denied")
    return a_file

non_buggy_open_file()
