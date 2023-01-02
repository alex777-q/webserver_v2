test: test.o
	g++ -o TEST test.o
test.o :
	g++ -c test.cpp -o test.o
