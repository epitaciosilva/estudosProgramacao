#include "../include/analiseDocumento.hpp"

AnaliseDocumento::AnaliseDocumento() { }

AnaliseDocumento::~AnaliseDocumento() { }
    
void AnaliseDocumento::realizarAnalise(std::string nomeArquivo) {
    std::vector<std::string> linhas;
    Arquivo::ler(linhas, nomeArquivo);

    Arquivo::split(this->stopWords, linhas[0]);   

    for(size_t i = 1; i < linhas.size(); i++) {
        Arquivo::split(this->palavras, linhas[i]);
    }
    
    size_t j;
    for(size_t i = 0; i < this->palavras.size(); i++) {
        for(j = 0; j < this->stopWords.size(); j++) {
            if(this->palavras[i].compare(this->stopWords[j]) == 0) {
                j = -1;
                break;
            }
        }

        if(j != (size_t)-1) {
            size_t t;
            for(t = 0; t < this->analise.size(); t++) {
                if(this->palavras[i].compare(this->analise[t]) == 0) {
                    this->contador[t] += 1;
                    t = this->analise.size() + 1;
                    break;
                }
            }

            if(t != this->analise.size() + 1) {
                this->analise.push_back(palavras[i]);
                this->contador.push_back(1);
            }
        }
    }

    this->ordenarVetorString();
    Arquivo::exportarArquivo(this->analise, this->contador, nomeArquivo);
}

void AnaliseDocumento::ordenarVetorString() {
    // algoritmo de inserção
    for(size_t i = 0; i < this->analise.size(); i++) {
        std::string palavra = this->analise[i];
        std::string letra = this->analise[i].substr(0,1);
        int cont = this->contador[i];
        size_t posicaoInsercao = i;
        
        while(posicaoInsercao > 0 && (this->analise[posicaoInsercao-1].compare(palavra) > 0 ||
            (letra.compare(this->analise[posicaoInsercao].substr(0,1)) == 0 && this->contador[posicaoInsercao] > this->contador[posicaoInsercao-1]))) {
            
            this->analise[posicaoInsercao] = this->analise[posicaoInsercao-1];
            this->contador[posicaoInsercao] = this->contador[posicaoInsercao-1];
            posicaoInsercao--;            
        }
        this->analise[posicaoInsercao] = palavra;
        this->contador[posicaoInsercao] = cont; 
    }
}