PROG = programa
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o conta.o movimentacao.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o:
	$(CC) $(CPPFLAGS) -c ./src/main.cpp

conta.o: ./include/conta.hpp
	$(CC) $(CPPFLAGS) -c ./src/conta.cpp

movimentacao.o: ./include/movimentacao.hpp
	$(CC) $(CPPFLAGS) -c ./src/movimentacao.cpp

clean: 
	rm -f *.o
