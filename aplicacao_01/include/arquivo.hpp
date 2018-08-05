#ifndef _ARQUIVO_
#define _ARQUIVO_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class Arquivo {
	public: 
		Arquivo();
		~Arquivo();
		static void ler(std::vector<std::string>& vetor, std::string nomeArquivo);
		static void split(std::vector<std::string> &vetor, std::string& texto, char delim = ' ');
		static void exportarArquivo(std::vector<std::string>& palavras, std::vector<int>& contagem, std::string nomeArquivo);
};

#endif