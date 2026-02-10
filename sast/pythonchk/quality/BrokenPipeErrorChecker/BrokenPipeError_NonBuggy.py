import subprocess as sub

p = sub.Popen(["ls", "-al", "../"], stdin=sub.PIPE, stdout=sub.PIPE)

p.stdout.read()

try:
    p.stdin.write("ls\n")
except BrokenPipeError:
    print ("Broken Pipe Error")