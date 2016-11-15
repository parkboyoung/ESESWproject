CC = gcc
CFLAGS = -lncurses -Iinclude/
OBJFILES = main.o main_funcs.o

APP:	main.o main_funcs.o
	gcc -o APP -g -Wall main.o main_funcs.o -lncurses

main.o: src/main.c
	gcc -o main.o -g -Wall -c src/main.c -lncurses -Iinclude/

main_funcs.o:  src/main_funcs.c
	gcc -o main_funcs.o -g -Wall -c src/main_funcs.c -lncurses -Iinclude/

clean:
	rm *.o APP
