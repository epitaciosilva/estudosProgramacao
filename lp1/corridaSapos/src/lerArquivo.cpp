#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../include/lerArquivo.hpp"

LerArquivo::LerArquivo() { }

LerArquivo::~LerArquivo() { }
 
void LerArquivo::lerArquivo(std::string localArquivo) {
    std::string line;
    std::ifstream arquivo(localArquivo);
    
    if(arquivo.is_open()) {
        while(getline(arquivo, line)) {
            this->linhas.push_back(line);
        }
    } else {
        std::cout << "Erro na leitura do arquivo" << std::endl;
    }
    
    arquivo.close();
}

std::vector<std::string> LerArquivo::getLinhas() {
    return this->linhas;
}