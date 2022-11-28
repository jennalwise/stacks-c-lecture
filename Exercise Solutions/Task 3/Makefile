CC = clang
CFLAGS = -ansi -g -Wall -std=gnu11

all: testListStack

testListStack: listStackWithMin.o test.o
	$(CC) -o test $^

listStack.o: listStackWithMin.c listStackWithMin.h stack.h
	$(CC) $(CFLAGS) -c $<

test.o: test.c listStackWithMin.h stack.h
	$(CC) $(CFLAGS) -c $<

binaries = test testListStack

clean:
	rm -f *.o $(binaries)
		