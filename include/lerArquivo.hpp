#ifndef _LERARQUIVO_
#define _LERARQUIVO_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class LerArquivo {
	private:
		std::vector<std::string> linhas;

	public: 
		LerArquivo();
		~LerArquivo();
		void ler(std::string nomeArquivo);
		std::vector<std::string> getLinhas();

};

#endif