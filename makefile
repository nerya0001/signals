CC=gcc
FLAGS=-Wall -g

all: main 

main: main.o  
	$(CC) $(FLAGS) main.o -o main

main.o: main.c 
	$(CC) $(FLAGS) -c main.c	


.PHONY: clean all

clean:
	rm -f *.o *.a main 



