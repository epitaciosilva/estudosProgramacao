PROG = programa
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic
OBJS = main.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o:
	$(CC) $(CPPFLAGS) -c main.cpp

# lista.o: lista.hpp
# 	$(CC) $(CPPFLAGS) -c lista.hpp

clean: 
	rm -f *.o && rm $(PROG)
