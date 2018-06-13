#include "../include/principal.hpp"

Principal::Principal(){
	// bloco = 0;
	// endereco = 0;
	// conteudo = 0;
}

// Principal::Principal(int qtdBlocos, int qtdEnderecos) {
// 	this->blocos = new int[qtdBlocos];
// 	this->enderecos = new int[qtdEnderecos];
// 	this->conteudos = new int[qtdEnderecos*qtdBlocos];
// }

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