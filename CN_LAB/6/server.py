import socket
#random port number
port= 5060
#assume data =16 as we donno the data length- if 5 len of message then need 1 to store 5, if data len 100 then need 3 to store that
data=16
disconnected_msg="END"
format="utf-8"
#server name
hostname= socket.gethostname()
#host ip address
host_addr= socket.gethostbyname(hostname)
server_socket_address= (host_addr, port)
#IPV4 set, TCP set- server var is the obj for server
server= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#bind
server.bind(server_socket_address)
#listen
server.listen()
print("Server is listening")

while True:
    #address has client's socket address
    conn,addr= server.accept()
    print("Connected to: ", addr)
    connected= True

    while connected:
        #client send hello- hello's length is 5 but length of the length of hello is 1 as it takes 1 place to store 5
        #initial- len of the msg sent by client
        initial = conn.recv(data).decode(format)
        print("Length of the message to be sent", initial)
        if initial:
            meg_length= int(initial)
            msg= conn.recv(meg_length).decode(format)

            if msg==disconnected_msg:
                print("Terminating connection with", addr )
                conn.send("Nice to meet you".encode(format))
                connected=False
            else:
                count = 0

                for char in msg:
                    if char in "aeiouAEIOU":
                        count += 1

                if count == 0:
                    conn.send("Not enough vowles".encode(format))
                elif count <=2:
                    conn.send("Enough vowles ig...".encode(format))
                else:
                    conn.send("Too many vowles".encode(format))
    conn.close() 
