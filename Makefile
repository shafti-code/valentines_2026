PROJECT_NAME = bin
main: src/main.c
	gcc src/main.c -o build/$(PROJECT_NAME)

run: main
	./build/$(PROJECT_NAME)
