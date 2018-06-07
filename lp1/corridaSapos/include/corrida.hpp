#ifndef _CORRIDA_
#define _CORRIDA_

#include <iostream>
#include <string>
#include <vector>

#include "sapo.hpp"
#include "pista.hpp"

class Corrida { 
    private:
        std::vector<Pista> pistas;
        std::vector<Sapo> sapos;
        std::vector<Sapo> classificacao;
        
    public:
        Corrida();
        ~Corrida();
        void iniciarCorrida();
        void inserirSaposPistas(std::vector<std::string> linhas);
        void imprimirSaposPistas();
        void imprimirRank();
};

#endif