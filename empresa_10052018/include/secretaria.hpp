#ifndef _SECRETARIA_HPP_
#define _SECRETARIA_HPP_

#include <string>
#include <iostream>
#include "funcionario.hpp"
using namespace std;

class Secretaria : public Funcionario {
    protected:
        string ramal;

    public:
        Secretaria();
        Secretaria(string nome, double salario, string dataAdmissao, string ramal);
        ~Secretaria();
        friend void operator>> (istream &i, Secretaria &secretaria);
        friend ostream& operator<< (ostream &o, Secretaria secretaria);
};

#endif