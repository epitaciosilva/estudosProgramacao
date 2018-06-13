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

void Principal::inicializarMemoria(int qtdBlocos, int qtdPalavras) {
	this->principal = (int **) malloc(qtdBlocos*qtdPalavras * sizeof(int*));
	for(int i = 0; i < qtdBlocos*qtdPalavras; i++) {
		this->principal[i] =  (int *) malloc(3 * sizeof(int));
		
		this->principal[i][0] = i/qtdPalavras; 
		this->principal[i][1] = i;
		this->principal[i][2] = 0;	 
	}
}

Principal::~Principal() { }