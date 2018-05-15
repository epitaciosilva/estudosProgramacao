#ifndef _EMPRESA_HPP_
#define _EMPRESA_HPP_

#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "funcionario.hpp"

class Empresa {
    private: 
        string nome;
        string cnpj;
        vector<Funcionario> funcionarios;

    public:
        Empresa();
        ~Empresa();
        string getNome();
        friend void operator>> (istream &i, Empresa &empresa);
        template<typename Type>
        void cadastrarProfissional(Type funcionario);
};

#endif