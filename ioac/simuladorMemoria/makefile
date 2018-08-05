PROG = executavel
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o principal.o cache.o arquivo.o controle.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o build/ 
	mv $(PROG) bin/

main.o: 
	$(CC) $(CPPFLAGS) -c src/main.cpp

principal.o: include/principal.hpp
	$(CC) $(CPPFLAGS) -c src/principal.cpp

cache.o: include/cache.hpp
	$(CC) $(CPPFLAGS) -c src/cache.cpp

arquivo.o: include/arquivo.hpp
	$(CC) $(CPPFLAGS) -c src/arquivo.cpp

controle.o: include/controle.hpp
	$(CC) $(CPPFLAGS) -c src/controle.cpp

clean:
	rm -f bin/$(PROG)
	rm -f build/*.o
