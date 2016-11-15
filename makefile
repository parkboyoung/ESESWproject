CC = gcc
CFLAGS1 = -g -Wall
CFLAGS2 = -lncurses -Iinclude/
OBJFILES = *.o

APP:	main.o main_funcs.o
	gcc -o APP $(CFLAGS1) $(OBJFILES) $(CFLAGS2)

%.o: src/%.c
	$(CC) -o $@ $(CFLAGS1) -c $< $(CFLAGS2)

clean:
	rm *.o APP
