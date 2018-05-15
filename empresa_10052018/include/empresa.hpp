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
        void cadastrarProfissional(Funcionario funcionario);
        static size_t encontrarEmpresa(vector<Empresa> empresas, string nomeEmpresa);
        friend ostream& operator<< (ostream &o, Empresa &empresa);
        friend void operator<< (ostream &o, vector<Funcionario> funcionarios);
        friend void operator>> (istream &i, vector<Empresa> &empresas);
        string getNome();
        vector<Funcionario> getFuncionarios();
};

#endif