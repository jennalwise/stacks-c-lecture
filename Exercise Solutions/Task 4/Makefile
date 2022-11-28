CC = clang
CFLAGS = -ansi -g -Wall -std=gnu11

all: testListStack

testListStack: listStack.o test.o
	$(CC) -o test $^

listStack.o: listStack.c listStack.h stack.h
	$(CC) $(CFLAGS) -c $<

test.o: test.c listStack.h stack.h
	$(CC) $(CFLAGS) -c $<

binaries = test testListStack

clean:
	rm -f *.o $(binaries)
		