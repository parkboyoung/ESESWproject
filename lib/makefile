AR = ar
CC = gcc
LIB = libfuncs.a
OBJFILES = calender.o memo.o timetable.o 
CFLAGS1 = -g -Wall
CFLAGS2 = -lcurses -I../include

$(LIB): $(OBJFILES)
	$(AR) crv $(LIB) $(OBJFILES)

%.o: %.c
	$(CC) -o $@ $(CFLAGS1) -c $< $(CFLAGS2)

clean: 
	rm -f $(OBJFILES) $(LIB)


