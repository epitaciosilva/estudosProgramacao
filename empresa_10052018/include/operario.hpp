#ifndef _OPERARIO_HPP_
#define _OPERARIO_HPP_

#include <string>
#include <iostream>
#include "funcionario.hpp"
using namespace std;

class Operario : public Funcionario {
    protected:
        string nomeEmpresa;

    public:
        Operario();
        Operario(string nome, double salario, string dataAdmissao, string nomeEmpresa);
        ~Operario();
        friend void operator>> (istream &i, Operario &operario);
};

#endif