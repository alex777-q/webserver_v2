.PHONY:all
all:client server client1

client:client.c
	gcc -o $@ $^

server:server.c
	gcc -o $@ $^

client1:client1.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -rf client server client1
