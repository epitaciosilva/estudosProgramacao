PROG = executavel
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o arquivo.o analiseDocumento.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o build/ && mv $(PROG) bin/

main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp

arquivo.o: include/arquivo.hpp
	$(CC) $(CPPFLAGS) -c src/arquivo.cpp

analiseDocumento.o: include/analiseDocumento.hpp
	$(CC) $(CPPFLAGS) -c src/analiseDocumento.cpp

clean: 
	rm -f build/*.o
	rm -f bin/$(PROG)