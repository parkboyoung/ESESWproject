AR = ar
cc = gcc
LIB = libfuncs.a
OBJFILES = calender.o memo.o timetable.o 
CFLAGS1 = -g -Wall
CFLAGS2 = -L../include -lncurses

$(LIB): $(OBJFILES)
	$(AR) rv $(LIB) $(OBJFILES)

%.o: %.c
	$(CC) -o $@ $(CFLAGS1) -c $< $(CFLAGS2)

clean: 
	rm -f $(OBJFILES) $(LIB)


