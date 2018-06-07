#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#include "../include/corrida.hpp"
#include "../include/pista.hpp"
#include "../include/sapo.hpp"

Corrida::Corrida() { }

Corrida::~Corrida() { }

void Corrida::inserirSaposPistas(std::vector<std::string> linhas) {
    size_t i = 1;

    while(linhas[i] != "PISTAS") {
        std::vector<std::string> atributos;
        std::string pedaco = "";
        for(auto caract:linhas[i]) {
            if(caract != '-' && caract != '\n') {
                pedaco += caract;
            }else if(pedaco != "") {
                atributos.push_back(pedaco);
                pedaco = "";
            }
        }

        if(pedaco != "") {
            atributos.push_back(pedaco);
        }

        Sapo sapo(atributos[0], atributos[1]);
        this->sapos.push_back(sapo);
        i++;
    }
    
    i++;

    while(i < linhas.size()) {
        std::vector<std::string> atributos;
        std::string pedaco = "";
        
        for(auto caract:linhas[i]) {
            if(caract != '-' && caract != '\n') {
                pedaco += caract;
            }else if(pedaco != "") {
                atributos.push_back(pedaco);
                pedaco = "";
            }
        }

        if(pedaco != "") {
            atributos.push_back(pedaco);
        }

        std::string::size_type sz;  
        int distancia = std::stoi(atributos[1], &sz);

        Pista pista(atributos[0], distancia);
        this->pistas.push_back(pista);
        i++;
    }

    this->imprimirSaposPistas();
} 

void Corrida::imprimirSaposPistas() {
    for(size_t i = 0; i < this->sapos.size(); i++) {
        std::cout << "\n------ Sapo " << i+1 << " ------"<< std::endl;
        std::cout << "Descricao: " << this->sapos[i].getDescricao() << std::endl;
        std::cout << "Identificador: " << this->sapos[i].getIdentificador() << std::endl;
    }

    for(size_t i = 0; i < this->pistas.size(); i++) {
        std::cout << "\n------ Pista " << i+1 << " ------"<< std::endl;
        std::cout << "Descricao: " << this->pistas[i].getDescricao() << std::endl;
        std::cout << "Distancia: " << this->pistas[i].getDistancia() << std::endl;
    }
}

void Corrida::corrida() {
    for(size_t i = 0; i < this->sapos.size(); i++) {
        
        for(size_t j = 0; j < this->classificacao.size(); j++) {
            if(this->sapos[i].getIdentificador() == this->classificacao[j].getIdentificador()) {
                continue;
            }
        }

        this->sapos[i].pular();
        
        if(this->sapos[i].getDistanciaPercorrida() >= this->pistas[0].getDistancia()) {
            this->classificacao.push_back(this->sapos[i]);
        }

        if(this->sapos.size() == this->classificacao.size()) {
            break;
        } else if(i+1 == this->sapos.size()) {
            i = 0;
        }
    }
}