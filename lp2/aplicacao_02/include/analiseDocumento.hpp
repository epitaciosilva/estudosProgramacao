#ifndef _ANALISE_DOCUMENTO_
#define _ANALISE_DOCUMENTO_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

#include "arquivo.hpp"

class AnaliseDocumento {
	public: 
		AnaliseDocumento();
		~AnaliseDocumento();
		void realizarAnalise(std::string nomeArquivo, std::vector<std::string> colunas, char delim = ' ');
};

#endif