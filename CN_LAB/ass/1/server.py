import socket

port = 5070
data = 16
disconnected_msg = "END"
format = "utf-8"

hostname = socket.gethostname()
host_addr = socket.gethostbyname(hostname)
server_socket_address = (host_addr, port)

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(server_socket_address)
server.listen()
print("Server is listening")

while True:
    conn, addr = server.accept()
    print("Connected to: ", addr)
    connected = True

    while connected:
        initial = conn.recv(data).decode(format)
        if initial:
            msg_length = int(initial)
            msg = conn.recv(msg_length).decode(format)

            if msg == disconnected_msg:
                print("Terminating connection with", addr)
                conn.send("Connection terminated".encode(format))
                connected = False
            else:
                hours = int(msg)
                if hours <= 40:
                    salary = hours * 200
                else:
                    salary = 8000 + (hours - 40) * 300

                response = "Salary: Tk " + str(salary)
                conn.send(response.encode(format))
    conn.close()
