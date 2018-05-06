PROG = programa
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic
OBJS = main.o book.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o:
	$(CC) $(CPPFLAGS) -c main.cpp

book.o: book.hpp
	$(CC) $(CPPFLAGS) -c book.cpp

clean: 
	rm -f *.o && rm $(PROG)
