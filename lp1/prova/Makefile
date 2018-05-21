PROG = executavel
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o livro.o cd.o dvd.o midia.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o build/ && mv $(PROG) bin/

main.o: 
	$(CC) $(CPPFLAGS) -c src/main.cpp

livro.o: include/livro.hpp
	$(CC) $(CPPFLAGS) -c src/livro.cpp

cd.o: include/cd.hpp
	$(CC) $(CPPFLAGS) -c src/cd.cpp

dvd.o: include/dvd.hpp
	$(CC) $(CPPFLAGS) -c src/dvd.cpp

midia.o: include/midia.hpp
	$(CC) $(CPPFLAGS) -c src/midia.cpp

clean: 
	rm -f build/*.o 
	rm -f bin/$(PROG)
