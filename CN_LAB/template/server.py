import socket

HOST = '127.0.0.1'
PORT = 8080

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen()

print("Server is listening...")

while True:
    conn, addr = server.accept()
    print("Connected by:", addr)

    while True:
        data = conn.recv(1024).decode()
        if not data:
            print("Client disconnected")
            break

        print("Client:", data)
        conn.send(data.encode())

    conn.close()
