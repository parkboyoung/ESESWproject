CC = gcc
CFLAGS1 = -g -Wall
OBJFILES = main.o main_funcs.o
CFLAGS2 = -L../lib -lfuncs -lcurses -I../include/

APP: $(OBJFILES)
	$(CC) -o APP $(CFLAGS1) $(OBJFILES) $(CFLAGS2) -lpthread

%.o: %.c
	$(CC) -o $@ $(CFLAGS1) -c $< $(CFLAGS2)

clean: 
	rm *.o APP 
