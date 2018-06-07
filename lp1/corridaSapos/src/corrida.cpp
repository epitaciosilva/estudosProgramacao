#include <iostream>
#include <string>

#include "../include/corrida.hpp"
#include "../include/pista.hpp"
#include "../include/sapo.hpp"

Corrida::Corrida() { }

Corrida::~Corrida() { }

Corrida::Corrida(Pista pista) {
    this->pista = pista;
}

void Corrida::corrida() {
    for(size_t i = 0; i < this->sapos.size(); i++) {
        
        for(size_t j = 0; j < this->classificacao.size(); j++) {
            if(this->sapos[i].getIdentificador() == this->classificacao[j].getIdentificador()) {
                continue;
            }
        }

        this->sapos[i].pular();
        
        if(this->sapos[i].getDistanciaPercorrida() >= this->pista.getDistancia()) {
            this->classificacao.push_back(this->sapos[i]);
        }

        if(this->sapos.size() == this->classificacao.size()) {
            break;
        } else if(i+1 == this->sapos.size()) {
            i = 0;
        }
    }
}