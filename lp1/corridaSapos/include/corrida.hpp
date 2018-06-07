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
        std::vector<Sapo *> classificacao;
        size_t buscarCorrida(std::string nomePista);
        
    public:
        Corrida();
        ~Corrida();
        void iniciarCorrida(std::string nomePista);
        void inserirSapos(std::string localArquivo);
        void inserirPistas(std::string localArquivo);
        void imprimirEstatisticasSapos();
        void imprimirEstatisticasPistas();
        void imprimirSapos();
        void imprimirRank(size_t indexPista);
        void escreverSapo(Sapo sapo, std::string localArquivo);
        void escreverPista(Pista pista, std::string localArquivo);
        
};

#endif