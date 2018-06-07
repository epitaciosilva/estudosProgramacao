/**
* @author Epitácio Bessa
* @file corrida.cpp
* @sa https://github.com/epitaciosilva/cppClass/blob/corridaSapos/lp1/corridaSapos/include/pista.hpp
* @since 29/05/18
* @date 07/06/18
*/

#ifndef _PISTA_
#define _PISTA_

#include <iostream>
#include <string>
#include <vector>

class Pista { 
    private:
        std::string descricao;
        int distancia;
        
    public:
        Pista();
        ~Pista();
        Pista(std::string descricao, int distancia);
        std::string getDescricao();
        int getDistancia();
        friend std::ostream& operator<< (std::ostream &o, Pista pista);
};

#endif