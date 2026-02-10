import pickle
import socket
import threading


# buggy client side
class NonBuggyConnectionThread(threading.Thread):
    def run(self):
        client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            client.connect(('localhost', 2727))              # @violation
        except ConnectionRefusedError:
            print("Connection Refused")
        except ConnectionAbortedError:
            print("Connection Aborted")

        for x in range(10):
            client.send(pickle.dumps(x))
            print('Sent:', str(x))
            print('Received:', repr(pickle.loads(client.recv(1024))))

        client.close()


for x in range(5):
    NonBuggyConnectionThread().start()

