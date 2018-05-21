#ifndef _FUNCIONARIO_HPP_
#define _FUNCIONARIO_HPP_

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Funcionario {
    protected: 
        string nome;
        double salario;
        string dataAdmissao;  

    public:
        Funcionario();
        ~Funcionario();
        void aumentoSalario();
        friend void operator>> (istream &i, Funcionario &funcionario);
        friend ostream& operator<< (ostream &o, Funcionario funcionario);
        // friend void operator<< (ostream &o, vector<Funcionario> &funcionarios);
        string getNome();
        double getSalario();
        string getDataAdmissao();
};

#endif