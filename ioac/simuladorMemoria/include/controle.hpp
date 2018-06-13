#ifndef _CONTROLE_HPP
#define _CONTROLE_HPP

#include <vector>
#include <string>

#include "cache.hpp"
#include "principal.hpp"
#include "arquivo.hpp"

class Controle {
	private:
		Cache cache;
		Principal principal;
		int tamanhoBloco;
		int linhasCache;
		int blocosPrincipal;
		int tipoMapeamento;
		int numeroConjuntos;
		int politicaSubstituicao;

	public:
		Controle();
		void inicializarMemorias(std::string arquivoConfiguracoes);
		~Controle();
};
#endif