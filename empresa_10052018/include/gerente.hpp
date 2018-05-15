#ifndef _GERENTE_HPP_
#define _GERENTE_HPP_

#include <string>
#include <iostream>
#include "funcionario.hpp"
using namespace std;

class Gerente : public Funcionario {
    protected:
        string senha;
        int numeroDeFuncionariosGerenciados;

    public:
        Gerente();
        Gerente(string nome, double salario, string dataAdmissao, string senha, int numeroDeFuncionariosGerenciados);
        ~Gerente();
        friend void operator>> (istream &i, Gerente &gerente);
    
};

#endif