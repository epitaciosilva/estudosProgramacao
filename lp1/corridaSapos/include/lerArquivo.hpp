/**
* @author Epitácio Bessa
* @file corrida.cpp
* @sa https://github.com/epitaciosilva/cppClass/blob/corridaSapos/lp1/corridaSapos/include/lerArquivo.hpp
* @since 29/05/18
* @date 07/06/18
*/

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
        void escreverPista(std::string localArquivo, Pista pista);
        void escreverSapo(std::string localArquivo, Sapo sapo); 
};

#endif