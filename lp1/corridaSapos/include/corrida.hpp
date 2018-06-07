#ifndef _CORRIDA_
#define _CORRIDA_

#include <iostream>
#include <string>
#include <vector>

#include "sapo.hpp"
#include "pista.hpp"

class Corrida { 
    private:
        Pista pista;
        std::vector<Sapo> sapos;
        std::vector<Sapo> classificacao;
        
    public:
        Corrida();
        Corrida(Pista pista);
        ~Corrida();
        void corrida();
};

#endif