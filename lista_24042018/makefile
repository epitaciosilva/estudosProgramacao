PROG = programa
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic
OBJS = main.o book.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o build/ && mv $(PROG) bin/
	
main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp

book.o: include/book.hpp
	$(CC) $(CPPFLAGS) -c src/book.cpp

clean: 
	rm -f build/*.o && rm bin/$(PROG)
