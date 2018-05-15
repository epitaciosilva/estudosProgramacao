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

void operator>> (istream &i, Operario &operario) {
    Funcionario *funcionario = new Funcionario();
    i >> *funcionario;

    operario.nome = funcionario->getNome();
    operario.salario = funcionario->getSalario();
    operario.dataAdmissao = funcionario->getDataAdmissao();
    
    cout << "\nDigite o nome da empresa: ";   
    getline(i, operario.nomeEmpresa);
}
