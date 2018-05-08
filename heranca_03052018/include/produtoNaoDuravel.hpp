#ifndef _PRODUTO_NAO_DURAVEL_HPP_
#define _PRODUTO_NAO_DURAVEL_HPP_

#include <string>
#include <iostream>
#include "produto.hpp"
using namespace std;

class ProdutoNaoDuravel : public Produto {
    protected:
        string dataValidade;
        string genero;

    public:
        ProdutoNaoDuravel();
        string getDataValidade();
        string getGenero();
    
};

#endif