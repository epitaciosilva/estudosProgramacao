#include "../include/principal.hpp"

Principal::Principal() { }

void Principal::inicializarMemoria(int qtdBlocos, int tamanhoBloco) {
	this->principal = (int **) std::malloc((qtdBlocos * tamanhoBloco * sizeof(int*)));
	
	for(int i = 0; i < (qtdBlocos*tamanhoBloco); i++) {
		this->principal[i] =  (int *) std::malloc(3 * sizeof(int*));

		this->principal[i][0] = i/tamanhoBloco; 
		this->principal[i][1] = i;
		//"aleatório"
		this->principal[i][2] = i/2;	 
	}
}

Principal::~Principal() { }

int ** Principal::getPrincipal() {
	return this->principal;
}

void Principal::show(int tamanhoPrincipal) {
	std::cout << "      Principal      \n";
	std::cout << "Bloco - Endereco - Conteudo\n";
	for(int i = 0; i < tamanhoPrincipal; i++) {
		std::cout << this->principal[i][0] << "        " << this->principal[i][1] << "        " << this->principal[i][2] << std::endl;
	}
}