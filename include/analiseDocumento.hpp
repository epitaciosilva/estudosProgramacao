#ifndef _ANALISE_DOCUMENTO_
#define _ANALISE_DOCUMENTO_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

#include "lerArquivo.hpp"

class AnaliseDocumento {
	private:
		std::vector<std::string> stopWords;
		std::vector<std::string> analise;
		std::vector<std::string> palavras;
		std::vector<int> contador;

	public: 
		AnaliseDocumento();
		~AnaliseDocumento();
		void realizarAnalise(std::string nomeArquivo);
};

#endif