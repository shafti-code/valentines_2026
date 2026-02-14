PROJECT_NAME = valentines

CC=gcc
CFLAGS=-lncurses

main: src/main.c
	$(CC) -O3 src/main.c -o build/$(PROJECT_NAME) $(CFLAGS)

run: main
	./build/$(PROJECT_NAME)
