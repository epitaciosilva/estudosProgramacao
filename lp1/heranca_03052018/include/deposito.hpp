#ifndef _DEPOSITO_HPP_
#define _DEPOSITO_HPP_

#include <iostream>
#include <vector>
using namespace std;

#include "produto.hpp"

class Deposito {
    private:
        vector<Produto> estoque;

    public:
        Deposito();
        ~Deposito();
        void adicionarProduto(Produto produto);
        void removerProduto(string nome);
        void quantidadeProdutos();
        void depositoVazio();
        void produtoMaiorValor();
};

#endif