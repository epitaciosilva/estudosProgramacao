#include "../include/cache.hpp"

Cache::Cache() { 
	this->cicloFixo = 0;
	this->cicloTemporal = 0;
}

void Cache::inicializarMemoria(int qtdBlocos, int tamanhoBloco) {
	this->cache = (int **) malloc(qtdBlocos*tamanhoBloco * sizeof(int*));
	for(int i = 0; i < qtdBlocos*tamanhoBloco; i++) {
		this->cache[i] =  (int *) malloc(7 * sizeof(int));
		
		this->cache[i][0] = i/tamanhoBloco; 
		this->cache[i][1] = 0;
		this->cache[i][2] = 0;	 
		this->cache[i][3] = 0;	 
		this->cache[i][4] = 0; 
		this->cache[i][5] = cicloTemporal; 
		this->cache[i][6] = cicloFixo; 
	}

	this->cicloTemporal++;
	this->cicloFixo++;
}

Cache::~Cache() { }

int ** Cache::getCache() {
	return this->cache;
}

void Cache::atualizarCache(int localSub, int tamanhoBloco, int **principal, int localMiss, int endereco, int conteudo) {
	for(int i = 0; i < tamanhoBloco; i++) {

		if(this->cache[localSub+i][1] != principal[localMiss+i][0]) {
			this->cache[localSub+i][4] = 1;
		
			//fifo
			this->cache[localSub+i][6] = this->cicloFixo;
			this->cicloFixo++;
		} else {
			this->cache[localSub+i][4] += 1;
		}

		this->cache[localSub+i][1] = principal[localMiss+i][0];
		this->cache[localSub+i][2] = principal[localMiss+i][1];

		//Caso seja um write (conteudo != 0), faz a substituição do conteúdo.
		if(conteudo != 0 && principal[localMiss+i][1] == endereco){
			// std::cout << (principal[localMiss+i][1] == endereco) << std::endl;
			this->cache[localSub+i][3] = conteudo;
			principal[localMiss+i][2] = conteudo;
		} else {
			this->cache[localSub+i][3] = principal[localMiss+i][2];
		}

		//lru
		this->cache[localSub+i][5] = this->cicloTemporal;
	}

	this->cicloTemporal++;
}

int Cache::lfu(int tamanhoCache, int tamanhoBloco) {
	int menosUsado = this->cache[0][4];
	int index = 0;

	for(int i = tamanhoBloco; i < tamanhoCache; i+=tamanhoBloco) {
		if(menosUsado > this->cache[i][4]) {
			menosUsado = this->cache[i][4];
			index = this->cache[i][0];
		}
	}
	
	return index;
}


int Cache::lru(int tamanhoCache, int tamanhoBloco) {
	int menosTempoUsado = this->cache[0][5];
	int index = 0;

	for(int i = tamanhoBloco; i < tamanhoCache; i+=tamanhoBloco) {
		if(menosTempoUsado > this->cache[i][5]) {
			menosTempoUsado = this->cache[i][5];
			index = this->cache[i][0];
		}
	}

	return index;
}

int Cache::fifo(int tamanhoCache, int tamanhoBloco) {
	int maisTempoNaCache = this->cache[0][6];
	int index = 0;

	for(int i = tamanhoBloco; i < tamanhoCache; i+=tamanhoBloco) {
		if(maisTempoNaCache > this->cache[i][6]) {
			maisTempoNaCache = this->cache[i][6];
			index = this->cache[i][0];
		}
	}
	
	return index;
}

int Cache::aleatorio(int tamanhoCache, int tamanhoBloco) {
	std::srand(std::time(nullptr));
	int linha = std::rand() % tamanhoCache;

	return this->cache[linha*tamanhoBloco][0];
}

void Cache::show(int tamanhoCache) {
	std::cout << "      CACHE      \n";
	std::cout << "Linha - Bloco - Endereco - Conteudo\n";

	for(int i = 0; i < tamanhoCache; i++) {
		std::cout << this->cache[i][0] << "        " << this->cache[i][1] << "        " << this->cache[i][2] << "        " << this->cache[i][3] << std::endl;
	}
}

void Cache::setCiclo(int bloco, int tamanhoBloco, int tipoSubstituicao) {
	if(tipoSubstituicao == 4) {
		for(int i = 0; i < tamanhoBloco; i++) {
			this->cache[bloco*tamanhoBloco+i][5] = this->cicloTemporal+1;
		}
		this->cicloTemporal++;
	} else if(tipoSubstituicao == 3) {
		for(int i = 0; i < tamanhoBloco; i++) {
			this->cache[bloco*tamanhoBloco+i][4]++;
		}
	}
}


void Cache::setFifu(int posicao) {
	this->cache[posicao][4] += 1;
}