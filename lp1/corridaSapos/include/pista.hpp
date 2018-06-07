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