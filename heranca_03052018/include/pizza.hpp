#ifndef _PIZZA_HPP_
#define _PIZZA_HPP_

#include <string>
#include <iostream>
#include "produtoNaoDuravel.hpp"
using namespace std;

class Pizza : public ProdutoNaoDuravel {
    public:
        Pizza();
        Pizza(string nome, double preco, string marca, string descricao, 
            string dataFabricacao, string dataValidade, string genero
        );
        ~Pizza();
};  

#endif