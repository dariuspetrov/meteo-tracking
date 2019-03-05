import socket

HOST = 'localhost'   # use '' to expose to all networks
PORT = 5000

def incoming(host, port):
    """Open specified port and yield requests"""
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.settimeout(10)
    sock.bind((host, port))
    sock.listen(0)
    try:
        while True:
            request, addr = sock.accept()
            yield request
            request.close()
    except socket.timeout:
        raise StopIteration
    finally:
        sock.close()

for request in incoming(HOST, PORT):
    print (request.recv(1024))