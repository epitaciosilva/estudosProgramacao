#include <string>
#include <iostream>
using namespace std;

#include "../include/funcionario.hpp"
#include "../include/operario.hpp"

Operario::Operario() { }

Operario::Operario(string nome, double salario, string dataAdmissao, string nomeEmpresa) { 
    this->nome = nome;
    this->salario = salario;
    this->dataAdmissao = dataAdmissao;
    this->nomeEmpresa = nomeEmpresa;
}

Operario::~Operario() { }

void Operario::aumentoSalario() {
    this->salario *= 5/100;
}

void operator>> (istream &i, Operario &operario) {
    Funcionario *funcionario = new Funcionario();
    i >> *funcionario;
    operario.nome = funcionario->getNome();
    operario.salario = funcionario->getSalario();
    operario.dataAdmissao = funcionario->getDataAdmissao();
    
    cout << "Digite o nome da empresa: ";   
    getline(i, operario.nomeEmpresa);
    i.ignore();
}

ostream& operator<< (ostream &o, Operario operario) {
    o << operario;
    o << "\nNome da empresa: " << operario.nomeEmpresa;
    
    return o;
}