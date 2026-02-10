import os

path = "C:"
# assume that file.txt exists
f = open("file.txt")
f.write("hello\n")
# BUG, IsADirectoryError
os.replace(f.name, path)                # @violation
f.close()

file = open("2016_06_06_UK_BackToSchool.html").read()
text_filtered = re.sub(r'http://', '/', file)
print (text_filtered)

with open ("2016_06_06_UK_BackToSchool.html", "wt") as out_file:
    out_file.write(text_filtered)

with open(os.path.join('/Users/Glenn/jack/HTML_Task/dest',), "w") as out_file:
    os.rename('2016_06_06_UK_BackToSchool.html','/Users/Glenn/jack/HTML_Task/dest')      # @violation