#include "../include/lerArquivo.hpp"

LerArquivo::LerArquivo() { }

LerArquivo::~LerArquivo() { }

void LerArquivo::ler(std::string nomeArquivo) {
    std::string line;
    std::ifstream arquivo(nomeArquivo);
    
    if(arquivo.is_open()) {
        //Essa função retorna todas as linhas individualmente do arquivo.
        while(getline(arquivo, line)) {
            this->linhas.push_back(line);
        }
    } else {
        //Caso aconteça algum erro na leitura do arquivo.
        std::cout << "Erro na leitura do arquivo" << std::endl;
        exit(1);
    }
    
    arquivo.close();
}

std::vector<std::string> LerArquivo::getLinhas() {
	return this->linhas;
}