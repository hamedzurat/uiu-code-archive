import socket
port= 5060
#16 byte data sent [if I send now- len 3- len of len 1- bnut space 16 so fill the rest by padding]
data=16
format="utf-8"
disconnected_msg="END"
# since its the same device so serevr and client host and ip are same, but in diffrent case will be diffrent
hostname= socket.gethostname()
host_addr= socket.gethostbyname(hostname)
server_socket_address= (host_addr, port)
client= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(server_socket_address)

def msg_send(msg):
    #client first send the buffer size
    message= msg.encode(format)
    msg_length=len(message)
    #everything first convert to str then encode
    msg_length= str(msg_length).encode(format)
    #padding- data is 16, msg is len 1, so 15 times pad with space
    msg_length+=b" "*(data-len(msg_length))
    #send len first then send msg
    client.send(msg_length)
    client.send(message)
    # set a big buffewr size
    print(client.recv(2048).decode(format))

inn = input()
msg_send(inn)
msg_send(disconnected_msg)
