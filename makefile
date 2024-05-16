all:
	gcc lib/hash.o src/main.c -o bin/hash
	./bin/hash