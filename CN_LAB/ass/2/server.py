import socket
import threading

port = 5080
data_len = 16
format = "utf-8"
disconnected_msg = "END"

hostname = socket.gethostname()
host_addr = socket.gethostbyname(hostname)
server_socket_address = (host_addr, port)

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(server_socket_address)
server.listen()
print("Server is listening")

clients = []


def broadcast(message, sender_conn):
    for client in clients:
        if client != sender_conn:
            client.send(message)


def handle_client(conn, addr):
    print("Connected to:", addr)
    connected = True

    while connected:
        initial = conn.recv(data_len).decode(format)
        if initial:
            msg_length = int(initial)
            msg = conn.recv(msg_length).decode(format)

            if msg == disconnected_msg:
                print("Terminating connection with", addr)
                clients.remove(conn)
                conn.send("Connection terminated".encode(format))
                connected = False
            else:
                broadcast_msg = msg
                broadcast_msg = broadcast_msg.encode(format)
                print(broadcast_msg.decode(format))
                broadcast(broadcast_msg, conn)

    conn.close()


while True:
    conn, addr = server.accept()
    clients.append(conn)
    thread = threading.Thread(target=handle_client, args=(conn, addr))
    thread.start()
