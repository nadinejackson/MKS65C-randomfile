all: random.o
	gcc random.o
random.o: random.c
	gcc -c random.c
run: a.out
	./a.out
