CC = gcc
AR = ar
FLAGS = -Wall -g

all: main.o myBank.o
	$(CC) $(FLAGS) -o main main.o myBank.o

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a main
