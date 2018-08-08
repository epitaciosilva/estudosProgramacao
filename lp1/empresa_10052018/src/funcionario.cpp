#include <string>
#include <iostream>
using namespace std;

#include "../include/funcionario.hpp"

Funcionario::Funcionario() { }

Funcionario::~Funcionario() { }

void Funcionario::aumentoSalario() {
    this->salario *= 1/100;
}

void operator>> (istream &i, Funcionario &funcionario) {
    cout << "Digite o nome do funcionario: ";
    getline(i, funcionario.nome);
    cout << "Digite o salario do funcionario: "; 
    i >> funcionario.salario;
    i.ignore();
    cout << "Digite a data de admissao do funcionario: ";
    getline(i, funcionario.dataAdmissao);
    i.ignore();
}

ostream& operator<< (ostream &o, Funcionario funcionario) {
    o << "\nNome: " << funcionario.nome;
    o << "\nSalario: " << funcionario.salario;
    o << "\nData de Admissao: " << funcionario.dataAdmissao;
    
    return o;
}

// void operator<< (ostream &o, vector<Funcionario> &funcionarios) {
//     for(size_t i = 0; i < funcionarios.size(); i++) {
//         cout << funcionarios[i];
//     }  
// }

string Funcionario::getNome() {
    return this->nome;
}

double Funcionario::getSalario() {
    return this->salario;
}

string Funcionario::getDataAdmissao() {
    return this->dataAdmissao;
}
