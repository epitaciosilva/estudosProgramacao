#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_

#include <iostream>
#include <cstdlib> 

class Principal {
	private:
		int **principal;

	public:
		Principal();
		~Principal();
		void inicializarMemoria(int qtdBlocos, int tamanhoBloco);
		int **getPrincipal();
		void show(int tamanhoCache);
};

#endif