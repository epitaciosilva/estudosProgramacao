#include "../include/cache.hpp"

Cache::Cache() { }

void Cache::inicializarMemoria(int qtdBlocos, int qtdPalavras) {
	this->cache = (int **) malloc(qtdBlocos*qtdPalavras * sizeof(int*));
	for(int i = 0; i < qtdBlocos*qtdPalavras; i++) {
		this->cache[i] =  (int *) malloc(4 * sizeof(int));
		
		this->cache[i][0] = i/qtdPalavras; 
		this->cache[i][1] = 0;
		this->cache[i][2] = 0;	 
		this->cache[i][3] = 0;	 
	}
}

Cache::~Cache() { }