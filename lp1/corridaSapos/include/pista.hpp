#ifndef _PISTA_
#define _PISTA_

#include <iostream>
#include <string>
#include <vector>

#include "sapo.hpp"

class Pista { 
    private:
        std::string descricao;
        int distancia;
        
    public:
        Pista();
        ~Pista();
        Pista(std::string descricao, int distancia);
        int getDistancia();
};

#endif