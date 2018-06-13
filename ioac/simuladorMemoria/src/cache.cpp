#include "../include/cache.hpp"

Cache::Cache() { }

void Cache::inicializarMemoria(int qtdBlocos, int tamanhoBloco) {
	this->cache = (int **) malloc(qtdBlocos*tamanhoBloco * sizeof(int*));
	for(int i = 0; i < qtdBlocos*tamanhoBloco; i++) {
		this->cache[i] =  (int *) malloc(4 * sizeof(int));
		
		this->cache[i][0] = i/tamanhoBloco; 
		this->cache[i][1] = 0;
		this->cache[i][2] = 0;	 
		this->cache[i][3] = 0;	 
	}
}

Cache::~Cache() { }

int ** Cache::getCache() {
	return this->cache;
}

void Cache::atualizarCache(int localSub, int tamanhoBloco, int **principal, int localMiss, int conteudo) {
	for(int i = 0; i < tamanhoBloco; i++) {
		this->cache[localSub+i][1] = principal[localMiss+i][0];
		this->cache[localSub+i][2] = principal[localMiss+i][1];

		//Caso seja um write (conteudo != 0), faz a substituição do conteúdo.
		if(conteudo == 0) {
			this->cache[localSub+i][3] = principal[localMiss+i][2];
		} else {
			this->cache[localSub+i][3] = conteudo;
		}
	}	
}