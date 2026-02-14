PROJECT_NAME = valentines

CC=gcc
CFLAGS=-lncurses

main: src/main.c
	$(CC) src/main.c -o build/$(PROJECT_NAME) $(CFLAGS) -g

run: main
	./build/$(PROJECT_NAME)
