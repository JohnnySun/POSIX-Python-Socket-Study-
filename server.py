#!/usr/bin/python2
import socket
HOST='127.0.0.1'
PORT=8888
s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(1)
while 1:
    conn, addr=s.accept()
    print 'Connected from', addr
    data=conn.recv(1024)
    print data
    conn.sendall("Received")
conn.close()
