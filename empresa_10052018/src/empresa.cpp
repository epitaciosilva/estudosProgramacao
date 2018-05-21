#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "../include/funcionario.hpp"
#include "../include/empresa.hpp"
#include "../include/gerente.hpp"
#include "../include/operario.hpp"
#include "../include/secretaria.hpp"

Empresa::Empresa() { }
Empresa::~Empresa() { }


void Empresa::cadastrarProfissional(Funcionario funcionario) {
    std::cin >> funcionario;
    this->funcionarios.push_back(funcionario);
}

void operator>> (istream &i,  vector<Empresa> &empresas) {
    Empresa empresa;
    i.ignore();
    std::cout << "\nDigite o nome da empresa: ";
    getline(i, empresa.nome);
    std::cout << "Digite o CNPJ: ";
    getline(i, empresa.cnpj);
    
    empresas.push_back(empresa);
}

ostream& operator<< (ostream &o, Empresa &empresa) {
    for(size_t i =0; i < empresa.funcionarios.size(); i++) {
        o << empresa.funcionarios[i] << endl;
    }

    return o;
}

void operator<< (ostream &o, vector<Funcionario> funcionarios) {
    for(size_t i = 0; i < funcionarios.size(); i++) {
        o << funcionarios[i];
    } 

    return o; 
}

size_t Empresa::encontrarEmpresa(vector<Empresa> empresas, string nomeEmpresa) {
    for(size_t i = 0; i < empresas.size(); i++) {
        if(empresas[i].getNome() == nomeEmpresa) {
            return i;
        }
    }

    //Evitar warning
    return (size_t)-1;
}

string Empresa::getNome() {
    return this->nome;
}

vector<Funcionario> Empresa::getFuncionarios() {
    return this->funcionarios;
}