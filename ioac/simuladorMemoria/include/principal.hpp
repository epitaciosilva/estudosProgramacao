#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_

#include <iostream>
#include <cstdlib> 

class Principal {
	private:
		int **principal;

	public:
		Principal();
		void inicializarMemoria(int qtdBlocos, int tamanhoBloco);
		int **getPrincipal();
		~Principal();
};

#endif