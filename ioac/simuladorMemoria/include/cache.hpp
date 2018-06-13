#ifndef _CACHE_HPP
#define _CACHE_HPP

#include <iostream>
class Cache {
	private:
		int **cache;

	public:
		Cache();
		void inicializarMemoria(int qtdBlocos, int tamanhoBloco);
		void atualizarCache(int localSub, int tamanhoBloco, int **principal, int localMiss, int conteudo = 0);
		int ** getCache();
		~Cache();
};
#endif