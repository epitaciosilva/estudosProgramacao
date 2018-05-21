#ifndef _CARRO_HPP_
#define _CARRO_HPP_

#include <string>
#include <iostream>
#include "produtoDuravel.hpp"
using namespace std;

class Carro : public ProdutoDuravel {
    private:
        int qtdPortas;
        string cor;
    
    public:
        Carro(string nome, double preco, string marca, string descricao, string dataFabricacao, 
            string materialPredominante, int durabilidade, int qtdPortas, string cor
        );
        ~Carro();
        int getQtdPortas();
        string getCor();
};

#endif