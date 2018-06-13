#ifndef _CACHE_HPP
#define _CACHE_HPP

#include <iostream>
class Cache {
	private:
		int **cache;

	public:
		Cache();
		void inicializarMemoria(int qtdBlocos, int qtdPalavras);
		~Cache();
};
#endif