#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "../include/ciclo.hpp"

Ciclo::Ciclo(){}

Ciclo::Ciclo(int ciclo) {
    this->ciclo = ciclo;
}

vector<Ciclo> Ciclo::ciclos() {
    Ciclo iff, id, ex, mem, wb;
    iff.setCiclo(1);
    id.setCiclo(2);
    ex.setCiclo(3);
    mem.setCiclo(4);
    wb.setCiclo(5);

    vector<Ciclo> ciclos;
    ciclos.push_back(iff);
    ciclos.push_back(id);
    ciclos.push_back(ex);
    ciclos.push_back(mem);
    ciclos.push_back(wb);
    
    return ciclos;
}

void Ciclo::setCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Ciclo::getCiclo() {
    return this->ciclo;
}

void Ciclo::setDisponivel(bool disponivel) {
    this->disponivel = disponivel;
}

bool Ciclo::getDisponivel() {
    return this->disponivel;
}