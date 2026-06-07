import socket
import threading

port = 5080
data_len = 16
format = "utf-8"
disconnected_msg = "END"

hostname = socket.gethostname()
host_addr = socket.gethostbyname(hostname)
server_socket_address = (host_addr, port)

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(server_socket_address)


def receive_messages():
    while True:
        msg = client.recv(2048).decode(format)
        if msg:
            print(msg)
        else:
            break


def msg_send(msg):
    message = msg.encode(format)
    msg_length = len(message)
    msg_length = str(msg_length).encode(format)
    msg_length += b" " * (data_len - len(msg_length))
    client.send(msg_length)
    client.send(message)


receive_thread = threading.Thread(target=receive_messages)
receive_thread.start()

while True:
    inn = input()
    msg_send(inn)
    if inn == disconnected_msg:
        break
