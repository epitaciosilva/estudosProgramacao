#ifndef _REFRIGERANTE_HPP_
#define _REFRIGERANTE_HPP_

#include <string>
#include <iostream>
#include "produtoNaoDuravel.hpp"
using namespace std;

class Refrigerante : public ProdutoNaoDuravel {
	private: 
		float volume;

    public:
        Refrigerante();
        Refrigerante(string nome, double preco, string marca, string descricao, 
            string dataFabricacao, string dataValidade, string genero, float volume
        );
        ~Refrigerante();
};

#endif