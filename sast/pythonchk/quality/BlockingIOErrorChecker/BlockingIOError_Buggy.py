import socket
import select

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.setblocking(0)

host = socket.gethostname()
port = 1234

# BUG, BlockingIOError
sock.connect((host, port))             # @violation

msg = "--> From the client\n"

select.select([], [sock], [])
if sock.send(bytes(msg, 'UTF-8')) == len(msg):
    print("sent ", repr(msg), " successfully.")

sock.close()