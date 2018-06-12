#ifndef _CACHE_HPP
#define _CACHE_HPP

class Cache {
	private:
		int linha;
		int bloco;
		int endereco;
		int conteudo;
		int contadorUtilizado;
		int contadorTemporal;

	public:
		Cache();
		~Cache();
};
#endif