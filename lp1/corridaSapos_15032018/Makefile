PROG = executavel
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic
OBJS = main.o sapo.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o build/ && mv $(PROG) bin/

main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp

sapo.o: include/sapo.h
	$(CC) $(CPPFLAGS) -c src/sapo.cpp

clean: 
	rm -f build/*.o
	rm -f bin/$(PROG)