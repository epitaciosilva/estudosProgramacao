#include "../include/analiseDocumento.hpp"

AnaliseDocumento::AnaliseDocumento() { }

AnaliseDocumento::~AnaliseDocumento() { }

void AnaliseDocumento::split(std::vector<std::string> &vetor, std::string instrucao, char c1) {
    std::string pedaco;

    for(auto caract:instrucao) {
        if(caract != c1) {
            pedaco += caract;
        }else if(pedaco != "") {
            if(pedaco.length() >= 6) {
                size_t c = pedaco.find("$");
                pedaco = pedaco.substr(c,3);
            }
            vetor.push_back(pedaco);
            pedaco = "";
        }
    }
    
    if(pedaco != "") {
        vetor.push_back(pedaco);
    }
    std::cout << vetor[vetor.size()-1] << std::endl;

}

void AnaliseDocumento::processar(std::string nomeArquivo) {
    LerArquivo arquivo;
    arquivo.ler(nomeArquivo);
    
    this->split(this->stopWords, arquivo.getLinhas()[0], ' ');
    
    for(size_t i = 1; i < arquivo.getLinhas().size(); i++) {
        this->split(this->palavras, arquivo.getLinhas()[i], ' ');
    }
    std::cout << "ASDASDASd" << std::endl;

    // i = 1 -> ignorar a primeira linha pois são as stopWords
    size_t j;
    for(size_t i = 1; i < palavras.size(); i++) {
        for(j = 0; j < this->stopWords.size(); j++) {
            if(arquivo.getLinhas()[i] == this->stopWords[j]) {
                palavras.erase(palavras.begin()+i);
                j = this->stopWords.size() + 1;
            }
        }
        if(j == this->stopWords.size() - 1) {
            this->analise.push_back(palavras[i]);
        }
    }
    
}