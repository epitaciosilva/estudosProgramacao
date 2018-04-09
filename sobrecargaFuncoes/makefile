PROG = programa
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic
OBJS = main.o tempo.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o:
	$(CC) $(CPPFLAGS) -c main.cpp

tempo.o: tempo.hpp
	$(CC) $(CPPFLAGS) -c tempo.cpp

clean: 
	rm -f *.o
