#!/usr/bin/python
import socket
HOST='127.0.0.1'
PORT=8888
s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
while 1:
    data=raw_input("Please Input:")
    bytes=s.sendall(data)
    data=s.recv(1024)
    print data
s.close
