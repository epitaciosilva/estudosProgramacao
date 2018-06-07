#ifndef _LERARQUIVO_
#define _LERARQUIVO_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../include/pista.hpp"
#include "../include/sapo.hpp"

class LerArquivo { 
    private:
        std::vector<std::string> linhas;
        std::string localArquivo;

    public:
        LerArquivo();
        ~LerArquivo();
        void lerArquivo(std::string localArquivo);
        std::vector<Pista> lerPistas(std::string localArquivo); 
        std::vector<Sapo> lerSapos(std::string localArquivo); 
        std::vector<std::string> getLinhas();
};

#endif