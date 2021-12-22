.PHONY = all clean
all: stringProg
FLAGS = -Wall -Werror -g
CC = gcc
stringProg: hw3.c
	$(CC) $(FLAGS) hw3.c -o stringProg
clean:
	rm -f *.o *.a stringProg