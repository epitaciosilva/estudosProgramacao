PROG = programa
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o arquivo.o instrucao.o ciclo.o pipeline.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o build/ && mv $(PROG) bin/

main.o:
	$(CC) $(CPPFLAGS) -c ./src/main.cpp

arquivo.o: ./include/arquivo.hpp
	$(CC) $(CPPFLAGS) -c ./src/arquivo.cpp

instrucao.o: ./include/instrucao.hpp
	$(CC) $(CPPFLAGS) -c ./src/instrucao.cpp

ciclo.o: ./include/ciclo.hpp
	$(CC) $(CPPFLAGS) -c ./src/ciclo.cpp

pipeline.o: ./include/pipeline.hpp
	$(CC) $(CPPFLAGS) -c ./src/pipeline.cpp

clean: 
	rm -f build/*.o && rm -f bin/$(PROG)
