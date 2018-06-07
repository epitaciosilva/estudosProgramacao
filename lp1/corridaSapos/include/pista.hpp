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
        int quantidadeSapos;
        std::vector<Sapo> sapos;
        std::vector<Sapo> classificacao;
        void vetorAuxiliar(int *vet, int tam);
        
    public:
        Pista();
        ~Pista();
        Pista(std::string descricao, int distancia, int quantidadeSapos);
        void setSapos(Sapo sapo);
        void corrida();

};

#endif