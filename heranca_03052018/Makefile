PROG = exec
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic
OBJS = main.o produto.o produtoDuravel.o produtoNaoDuravel.o deposito.o carro.o livro.o celular.o pizza.o chocolate.o refrigerante.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o build/ && mv $(PROG) bin/

main.o: 
	$(CC) $(CPPFLAGS) -c src/main.cpp

produto.o: include/produto.hpp
	$(CC) $(CPPFLAGS) -c src/produto.cpp

produtoDuravel.o: include/produtoDuravel.hpp
	$(CC) $(CPPFLAGS) -c src/produtoDuravel.cpp

produtoNaoDuravel.o: include/produtoNaoDuravel.hpp
	$(CC) $(CPPFLAGS) -c src/produtoNaoDuravel.cpp

deposito.o: include/deposito.hpp
	$(CC) $(CPPFLAGS) -c src/deposito.cpp

carro.o: include/carro.hpp
	$(CC) $(CPPFLAGS) -c src/carro.cpp

livro.o: include/livro.hpp
	$(CC) $(CPPFLAGS) -c src/livro.cpp

celular.o: include/celular.hpp
	$(CC) $(CPPFLAGS) -c src/celular.cpp

pizza.o: include/pizza.hpp
	$(CC) $(CPPFLAGS) -c src/pizza.cpp

chocolate.o: include/chocolate.hpp
	$(CC) $(CPPFLAGS) -c src/chocolate.cpp

refrigerante.o: include/refrigerante.hpp
	$(CC) $(CPPFLAGS) -c src/refrigerante.cpp

clean: 
	rm -f build/* && rm -f bin/*
