PROG = executavel
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic
OBJS = main.o sapo.o pista.o corrida.o lerArquivo.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o build/ && mv $(PROG) bin/

main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp

sapo.o: include/sapo.hpp
	$(CC) $(CPPFLAGS) -c src/sapo.cpp

pista.o: include/pista.hpp
	$(CC) $(CPPFLAGS) -c src/pista.cpp

corrida.o: include/corrida.hpp
	$(CC) $(CPPFLAGS) -c src/corrida.cpp

lerArquivo.o: include/lerArquivo.hpp
	$(CC) $(CPPFLAGS) -c src/lerArquivo.cpp

clean: 
	rm -f build/*.o
	rm -f bin/$(PROG)