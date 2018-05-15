#include <string>
#include <iostream>
using namespace std;

#include "../include/funcionario.hpp"
#include "../include/secretaria.hpp"

Secretaria::Secretaria() { }

Secretaria::Secretaria(string nome, double salario, string dataAdmissao, string ramal) { 
    this->nome = nome;
    this->salario = salario;
    this->dataAdmissao = dataAdmissao;
    this->ramal = ramal;
}

Secretaria::~Secretaria() { }

void Secretaria::aumentoSalario() {
    this->salario *= 8/100;
}

void operator>> (istream &i, Secretaria &secretaria) {
    Funcionario *funcionario = new Funcionario();
    i >> *funcionario;
    secretaria.nome = funcionario->getNome();
    secretaria.salario = funcionario->getSalario();
    secretaria.dataAdmissao = funcionario->getDataAdmissao();
    
    cout << "Digite o ramal da secretaria: ";   
    getline(i, secretaria.ramal);
    i.ignore();
}

ostream& operator<< (ostream &o, Secretaria secretaria) {
    o << secretaria;
    o << "\nRamal: " << secretaria.ramal;
    
    return o;
}