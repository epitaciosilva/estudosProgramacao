#ifndef _INSTRUCAO_H_
#define _INSTRUCAO_H_

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "ciclo.hpp"

class Instrucao {
    private:
        string instrucao;
        string descricao;
        int qtdRegistradores;
        int dependenciaRegistradores;     
        Ciclo ciclo;

    public:
        Instrucao();
        static vector<Instrucao> instrucoes();
        string getInstrucao();
        void setInstrucao(string instrucao);
        string getDescricao();
        void setDescricao(string descricao);
        int getQtdRegistradores();
        void setQtdRegistradores(int qtdRegistros);
        int getDependenciaRegistradores();
        void setDependenciaRegistradores(int dependenciaRegistradores);
        Ciclo getCiclo();
        void setCiclo(Ciclo ciclo);
        
        
};

#endif