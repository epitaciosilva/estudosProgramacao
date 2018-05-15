#include <string>
#include <iostream>
using namespace std;

#include "../include/funcionario.hpp"
#include "../include/gerente.hpp"

Gerente::Gerente() { }

Gerente::~Gerente() { }

Gerente::Gerente(string nome, double salario, string dataAdmissao, string senha, int numeroDeFuncionariosGerenciados) {
    this->nome = nome;
    this->salario = salario;
    this->dataAdmissao = dataAdmissao;
    this->senha = senha;
    this->numeroDeFuncionariosGerenciados = numeroDeFuncionariosGerenciados;
} 

void operator>> (istream &i, Gerente &gerente) {
    Funcionario *funcionario = new Funcionario();
    i >> *funcionario;

    gerente.nome = funcionario->getNome();
    gerente.salario = funcionario->getSalario();
    gerente.dataAdmissao = funcionario->getDataAdmissao();
    
    cout << "\nDigite a senha: ";   
    getline(i, gerente.senha);
    i >> gerente.numeroDeFuncionariosGerenciados;
    cout << "\nDigite o número de funcionários gerenciados: ";   
    i >> gerente.numeroDeFuncionariosGerenciados;    
}

