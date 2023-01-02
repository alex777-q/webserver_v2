.PHONY:all
all:semcreate semops semrmid semsetvalue semgetvalue

semcreate:semcreate.c
	gcc -o $@ $^

semops:semops.c
	gcc -o $@ $^

semrmid:semrmid.c
	gcc -o $@ $^

semsetvalue:semsetvalue.c
	gcc -o $@ $^

semgetvalue:semgetvalue.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -rf semcreate semops semrmid semsetvalue semgetvalue
