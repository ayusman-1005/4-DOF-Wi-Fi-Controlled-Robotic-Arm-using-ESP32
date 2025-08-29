import socket

server_ip = "10.24.169.25"  
port = 3333

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((server_ip, port))

s.sendall(b"50,35,75\n")  
print(s.recv(1024).decode())  

s.close()

