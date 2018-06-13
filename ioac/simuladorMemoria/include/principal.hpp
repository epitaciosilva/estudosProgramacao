#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_

#include <iostream>

class Principal {
	private:
		int * blocos;
		int * enderecos;
		int * conteudos;
		int ** principal;

	public:
		Principal();
		void inicializarMemoria(int qtdBlocos, int qtdPalavras);
		~Principal();
};

#endif