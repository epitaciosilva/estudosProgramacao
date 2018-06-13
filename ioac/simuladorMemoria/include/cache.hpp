#ifndef _CACHE_HPP
#define _CACHE_HPP

#include <iostream>
#include <ctime>
class Cache {
	private:
		int **cache;
		int cicloTemporal;
		int cicloFixo;

	public:
		Cache();
		~Cache();
		void inicializarMemoria(int qtdBlocos, int tamanhoBloco);
		void atualizarCache(int localSub, int tamanhoBloco, int **principal, int localMiss, int conteudo = 0);
		int lfu(int tamanhoCache, int tamanhoBloco);
		int lru(int tamanhoCache, int tamanhoBloco);
		int fifo(int tamanhoCache, int tamanhoBloco);
		int aleatorio(int tamanhoCache, int tamanhoBloco);
		void show(int tamanhoCache);
		void setCiclo(int bloco, int tamanhoBloco, int tipoSubstituicao);
		int ** getCache();
};
#endif