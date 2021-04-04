input.o: input.c input.h
	gcc -c input.c
action.o: action.c action.h input.o
	gcc -c action.c
main.o: main.c action.o input.o
	gcc -c main.c 

csv_program: main.o
	gcc -Wall main.o input.o action.o -g -o csv_program
