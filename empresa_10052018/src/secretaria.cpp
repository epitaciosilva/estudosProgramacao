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

void operator>> (istream &i, Secretaria &secretaria) {
    Funcionario *funcionario = new Funcionario();
    i >> *funcionario;

    secretaria.nome = funcionario->getNome();
    secretaria.salario = funcionario->getSalario();
    secretaria.dataAdmissao = funcionario->getDataAdmissao();
    
    cout << "\nDigite o ramal da secretaria: ";   
    getline(i, secretaria.ramal);
}
