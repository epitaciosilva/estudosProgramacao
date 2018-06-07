/**
* @author Epitácio Bessa
* @file sapo.cpp
* @sa https://github.com/epitaciosilva/cppClass/blob/corridaSapos/lp1/corridaSapos/src/pista.cpp
* @since 29/05/18
* @date 07/06/18
* @brief Implementações dos métodos da classe pista
*/

#include "../include/pista.hpp"

Pista::Pista() { }

Pista::~Pista() { }
 
Pista::Pista(std::string descricao, int distancia) {
    this->descricao = descricao;
    this->distancia = distancia;
}

std::ostream& operator<< (std::ostream &o, Pista pista) {
    o << "Descricao: " << pista.descricao << std::endl;
    o << "Distancia: " << pista.distancia << std::endl;
    
    return o;
}


int Pista::getDistancia() {
    return this->distancia;
}

std::string Pista::getDescricao() {
    return this->descricao;
}