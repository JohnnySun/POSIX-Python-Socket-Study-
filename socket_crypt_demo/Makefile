CC = gcc
CFLAGS=-fPIC
CFLAGS+=$(shell pkg-config --cflags libsodium)
LDFLAGS+=$(shell pkg-config --libs libsodium)

first: server client


server: server.o crypt.o
	$(CC) $^ -o $@ $(LDFLAGS)
server.o: server.c
	$(CC) -I. $(CFLAGS) -c $^ -o $@

client: client.o crypt.o
	$(CC) $^ -o $@ $(LDFLAGS)
client.o: client.c
	$(CC) -I. $(CFLAGS) -c $^ -o  $@
	
crypt.o: crypt.c
	$(CC) -I. $(CFLAGS) -c $^ -o $@

clean:
	rm -rf client server *.o
