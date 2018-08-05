#include "../include/lerArquivo.hpp"

LerArquivo::LerArquivo() { }

LerArquivo::~LerArquivo() { }

void LerArquivo::ler(std::vector<std::string>& vetor, std::string nomeArquivo) {
    std::string linha;
    std::ifstream arquivo(nomeArquivo);
    
    if(arquivo.is_open()) {
        //Essa função retorna todas as linhas individualmente do arquivo.
        while(getline(arquivo, linha)) {
            vetor.push_back(linha);
        }
    } else {
        //Caso aconteça algum erro na leitura do arquivo.
        std::cout << "Erro na leitura do arquivo" << std::endl;
        exit(1);
    }
    
    arquivo.close();
}

void LerArquivo::split(std::vector<std::string> &vetor, std::string& texto, char delim) {
    std::string palavra;
    std::istringstream linha(texto);
    
    //Essa função retorna todas as linhas individualmente do arquivo.
    while(getline(linha, palavra, delim)) {
        vetor.push_back(palavra);
    }
}