PROG = exec
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic
OBJS = main.o sapo.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o:
	$(CC) $(CPPFLAGS) -c main.cpp
sapo.o: sapo.h
	$(CC) $(CPPFLAGS) -c sapo.cpp


clean: 
	rm -f *.o exec
