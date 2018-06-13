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
		void read(int endereco, int conteudo = 0);
		void write(int endereco, int conteudo);
		int buscarPrincipal(int endereco);
		void mapeamentoDireto(int endereco, int conteudo = 0);
		void totalmenteAssossiativo(int endereco, int conteudo = 0);
		void parcialmenteAssossiativo(int endereco, int conteudo);
		void show();
		// void parcialmenteAssossiativo(int endereco, int conteudo = 0);
		~Controle();
};
#endif