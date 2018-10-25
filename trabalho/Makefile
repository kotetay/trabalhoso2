client: client.o
	cc -o client client.o -lncurses
client.o: client.c
	cc -c client.c
server: server.o
	cc -o server server.o
server.o: server.c
	cc -c server.c
clean:
	rm client.o client server.o server
