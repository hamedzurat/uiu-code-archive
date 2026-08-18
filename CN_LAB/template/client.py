import socket

HOST = '127.0.0.1'
PORT = 8080

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((HOST, PORT))

while True:
    msg = input("You: ")
    if msg.lower() == "exit":
        break

    client.send(msg.encode())
    data = client.recv(1024).decode()
    print("Server:", data)

client.close()
