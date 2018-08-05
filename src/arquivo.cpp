#include "../include/arquivo.hpp"

Arquivo::Arquivo() { }

Arquivo::~Arquivo() { }

void Arquivo::ler(std::vector<std::string>& vetor, std::string nomeArquivo) {
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

void Arquivo::split(std::vector<std::string> &vetor, std::string& texto, char delim) {
    std::string palavra;
    std::istringstream linha(texto);
    
    //Essa função retorna todas as linhas individualmente do arquivo.
    while(getline(linha, palavra, delim)) {
        vetor.push_back(palavra);
    }
}

void Arquivo::exportarArquivo(std::vector<std::string>& palavras, std::vector<int>& contagem, std::string nomeArquivo) {
    nomeArquivo = nomeArquivo.substr(0, nomeArquivo.find(".")) + ".out";
    std::ofstream arquivo(nomeArquivo, std::ostream::out);
    
    for(size_t i = 0; i < palavras.size(); i++) {
        arquivo << "(" << palavras[i] << ", " << contagem[i] << ")" << std::endl;
    }

    arquivo.close();
}