#include <iostream>
#include <string>

#include "../include/pista.hpp"
#include "../include/sapo.hpp"

Pista::Pista() { }

Pista::~Pista() { }
 
Pista::Pista(std::string descricao, int distancia) {
    this->descricao = descricao;
    this->distancia = distancia;
}

int Pista::getDistancia() {
    return this->distancia;
}

std::string Pista::getDescricao() {
    return this->descricao;
}