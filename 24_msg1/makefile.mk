.PHONY:all
all:msgcreate msgsnd msgrcv msgrmid

msgcreate:msgcreate.c
	gcc -o $@ $^

msgsnd:msgsnd.c
	gcc -o $@ $^

msgrcv:msgrcv.c
	gcc -o $@ $^

msgrmid:msgrmid.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -rf msgcreate msgsnd msgrcv msgrmid
