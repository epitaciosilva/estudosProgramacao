#ifndef _LERARQUIVO_
#define _LERARQUIVO_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
class LerArquivo {
	public: 
		LerArquivo();
		~LerArquivo();
		static void ler(std::vector<std::string>& vetor, std::string nomeArquivo);
		static void split(std::vector<std::string> &vetor, std::string& texto, char delim = ' ');

};

#endif