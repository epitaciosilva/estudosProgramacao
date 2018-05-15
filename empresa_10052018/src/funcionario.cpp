#include <string>
#include <iostream>
using namespace std;

#include "../include/funcionario.hpp"

Funcionario::Funcionario() { }

Funcionario::~Funcionario() { }

void operator>> (istream &i, Funcionario &funcionario) {
    cout << "\nDigite o nome do funcionario: ";
    getline(i, funcionario.nome);
    cout << "\nDigite o salario do funcionario: "; 
    i >> funcionario.salario;
    cout << "\nDigite a data de admissao do funcionario: ";
    getline(i, funcionario.dataAdmissao);
}

string Funcionario::getNome() {
    return this->nome;
}

double Funcionario::getSalario() {
    return this->salario;
}

string Funcionario::getDataAdmissao() {
    return this->dataAdmissao;
}
