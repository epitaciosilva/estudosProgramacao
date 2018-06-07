PROG = executavel
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic
OBJS = main.o sapo.o pista.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o build/ && mv $(PROG) bin/

main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp

sapo.o: include/sapo.hpp
	$(CC) $(CPPFLAGS) -c src/sapo.cpp

pista.o: include/pista.hpp
	$(CC) $(CPPFLAGS) -c src/pista.cpp

clean: 
	rm -f build/*.o
	rm -f bin/$(PROG)