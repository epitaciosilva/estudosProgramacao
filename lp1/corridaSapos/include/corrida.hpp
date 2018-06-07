#ifndef _CORRIDA_
#define _CORRIDA_

#include <iostream>
#include <string>
#include <vector>

#include "sapo.hpp"
#include "pista.hpp"
#include "lerArquivo.hpp"

class Corrida { 
    private:
        std::vector<Pista> pistas;
        std::vector<Sapo> sapos;
        std::vector<Sapo> classificacao;
        
    public:
        Corrida();
        ~Corrida();
        void iniciarCorrida();
        void inserirSapos(std::string localArquivo);
        void inserirPistas(std::string localArquivo);
        void imprimirEstatisticasSapos();
        void imprimirEstatisticasPistas();
        void imprimirSapos();
        void imprimirRank();
};

#endif