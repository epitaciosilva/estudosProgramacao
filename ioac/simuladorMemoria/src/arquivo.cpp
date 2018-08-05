#include "../include/arquivo.hpp"

Arquivo::Arquivo(){}

std::vector<std::string> Arquivo::lerArquivo(std::string nomeArquivo) {
    std::vector<std::string> linhas;
    std::string line;
    std::ifstream arquivo(nomeArquivo);
    
    if(arquivo.is_open()) {
        while(getline(arquivo, line)) {
            linhas.push_back(line);
        }
    }  
    
    arquivo.close();
    return linhas;
}