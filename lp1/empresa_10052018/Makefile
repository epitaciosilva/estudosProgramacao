PROG = executavel
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o funcionario.o gerente.o operario.o secretaria.o empresa.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o build/ && mv $(PROG) bin/

main.o: 
	$(CC) $(CPPFLAGS) -c src/main.cpp

funcionario.o: include/funcionario.hpp
	$(CC) $(CPPFLAGS) -c src/funcionario.cpp

gerente.o: include/gerente.hpp
	$(CC) $(CPPFLAGS) -c src/gerente.cpp

operario.o: include/operario.hpp
	$(CC) $(CPPFLAGS) -c src/operario.cpp

secretaria.o: include/secretaria.hpp
	$(CC) $(CPPFLAGS) -c src/secretaria.cpp

empresa.o: include/empresa.hpp
	$(CC) $(CPPFLAGS) -c src/empresa.cpp

clean: 
	rm -f build/*.o 
	rm -f bin/$(PROG)
