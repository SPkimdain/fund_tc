def non_buggy_open_file():
    filename = "nothing.txt"
    f = None
    try:
        f = open(filename)
    except FileNotFoundError:
        print("File Not Found")
    finally:
        if f is not None:
            f.close()

non_buggy_open_file()