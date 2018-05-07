#ifndef _CELULAR_HPP_
#define _CELULAR_HPP_

#include <string>
#include <iostream>
#include "produtoDuravel.hpp"
using namespace std;

class Celular : public ProdutoDuravel {
    public:
        Celular(string nome, double preco, string marca, string descricao, 
            string dataFabricacao, string getMaterialProdominante, int durabilidade
        );
        ~Celular();
};

#endif