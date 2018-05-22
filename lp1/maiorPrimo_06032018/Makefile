PROG = programa
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic
OGJS = main.o fatorial.o primalidade.o

$(PROG) : $(OGJS)
	$(CC) $(OGJS) -o $(PROG)

main.o :
	$(CC) $(CPPFLAGS) -c main.cpp

primalidade.o : primalidade.h
	$(CC) $(CPPFLAGS) -c primalidade.cpp

fatorial.o : fatorial.h
	$(CC) $(CPPFLAGS) -c fatorial.cpp

clean: 
	rm -r *.o
	rm $(PROG)
	
