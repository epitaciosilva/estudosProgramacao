#ifndef _LIVRO_HPP_
#define _LIVRO_HPP_

#include <string>
#include <iostream>
#include "produtoDuravel.hpp"
using namespace std;

class Livro : public ProdutoDuravel {
    private:
        int qtdPaginas;
    
    public:
        Livro(string nome, double preco, string marca, string descricao, string dataFabricacao,
            string getMaterialProdominante, int durabilidade, int getQtdPaginas
        );
        ~Livro();
        int getQtdPaginas();
};

#endif