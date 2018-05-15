#ifndef _FUNCIONARIO_HPP_
#define _FUNCIONARIO_HPP_

#include <string>
#include <iostream>
using namespace std;

class Funcionario {
    protected: 
        string nome;
        double salario;
        string dataAdmissao;  

    public:
        Funcionario();
        ~Funcionario();
        string getNome();
        double getSalario();
        string getDataAdmissao();
        friend void operator>> (istream &i, Funcionario &funcionario);
};

#endif