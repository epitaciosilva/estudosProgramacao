#ifndef _CHOCOLATE_HPP_
#define _CHOCOLATE_HPP_

#include <string>
#include <iostream>
#include "produtoNaoDuravel.hpp"
using namespace std;

class Chocolate : public ProdutoNaoDuravel {
    public:
        Chocolate();
        Chocolate(string nome, double preco, string marca, string descricao, 
            string dataFabricacao, string dataValidade, string genero
        );
        ~Chocolate();
};

#endif