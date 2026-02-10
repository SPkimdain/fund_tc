import pickle
import socket
import threading


# buggy client side
class BuggyConnectionThread(threading.Thread):
    def run(self):
        client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        # BUG, ConnectionRefusedError, ConnectionAbortedError, ConnectionResetError
        client.connect(('localhost', 2727))                         # @violation
        for x in range(10):
            client.send(pickle.dumps(x))
            print('Sent:', str(x))
            print('Received:', repr(pickle.loads(client.recv(1024))))

        client.close()


for x in range(5):
    BuggyConnectionThread().start()

