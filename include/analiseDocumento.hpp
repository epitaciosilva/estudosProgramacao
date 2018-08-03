#ifndef _ANALISE_DOCUMENTO_
#define _ANALISE_DOCUMENTO_

#include <string>
#include <vector>

#include "lerArquivo.hpp"

class AnaliseDocumento {
	private:
		std::vector<std::string> stopWords;
		std::vector<std::string> analise;
		std::vector<std::string> palavras;
	public: 
		AnaliseDocumento();
		~AnaliseDocumento();
		void split(std::vector<std::string> &vetor, std::string instrucao, char c1);
		void processar(std::string nomeArquivo);
};

#endif