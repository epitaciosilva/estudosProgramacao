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

void operator>> (istream &i, Empresa &empresa) {
    std::cout << "Digite o nome da empresa: ";
    getline(i, empresa.nome);
    std::cout << "Digite o CNPJ: ";
    getline(i, empresa.cnpj);
}

template <typename Type>
void Empresa::cadastrarProfissional(Type funcionario) {
    std::cin >> funcionario;
    this->funcionarios.push_back(funcionario);
}

string Empresa::getNome() {
    return this->nome;
}
