CC      = gcc
RM      = rm

default: main

main: src/main.c
	$(CC) src/main.c -o main

clean: main
	$(RM) main
