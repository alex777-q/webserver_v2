# target=all
# src=$(wildcard ./*.c)
# objs=$(patsubst %.c,%.o,$(src))
# $(target):$(objs)
# 	$(CC) $(objs) -o $(target)

# %.o: %.c
# 	$(CC) -c $< -o $@

# clean:
# 	rm %.o $(target) -f

# %:%.c
# 	$(CC) %^ -o %
all:client server
	gcc client server -o all

client:client.c
	gcc client.c -lpthread -o client

server:server.c
	gcc server.c -lpthread -o server

clean:
	rm all -f