#ifndef _PRODUTO_DURAVEL_HPP_
#define _PRODUTO_DURAVEL_HPP_

#include <string>
#include <iostream>
#include "produto.hpp"
using namespace std;

class ProdutoDuravel : public Produto {
    protected:
        string materialPredominante;
        int durabilidade;

    public:
        string getMaterialPredominante();
        int getDurabilidade();
};

#endif