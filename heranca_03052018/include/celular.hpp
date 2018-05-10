#ifndef _CELULAR_HPP_
#define _CELULAR_HPP_

#include <string>
#include <iostream>
#include "produtoDuravel.hpp"
using namespace std;

class Celular : public ProdutoDuravel {
	private:
		float polegadas;

    public:
        Celular(string nome, double preco, string marca, string descricao, 
            string dataFabricacao, string getMaterialProdominante, int durabilidade, float polegadas
        );
        ~Celular();
};

#endif