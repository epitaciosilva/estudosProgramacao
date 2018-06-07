#include <iostream>
#include <string>

#include "../include/pista.hpp"
#include "../include/sapo.hpp"

Pista::Pista() { }

Pista::Pista(std::string descricao, int distancia, int quantidadeSapos) {
    this->descricao = descricao;
    this->distancia = distancia;
    this->quantidadeSapos = quantidadeSapos;
}

void Pista::setSapos(Sapo sapo) {
    this->sapos.push_back(sapo);
}

void Pista::corrida() {
    for(size_t i = 0; i < this->sapos.size(); i++) {
        
        for(size_t j = 0; j < this->classificacao.size(); j++) {
            if(this->sapos[i].getIdentificador() == this->classificacao[j].getIdentificador()) {
                continue;
            }
        }

        this->sapos[i].pular();
        
        if(this->sapos[i].getDistanciaPercorrida() >= this->distancia) {
            this->classificacao.push_back(this->sapos[i]);
        }

        if(this->sapos.size() == this->classificacao.size()) {
            break;
        } else if(i+1 == this->sapos.size()) {
            i = 0;
        }
    }
}