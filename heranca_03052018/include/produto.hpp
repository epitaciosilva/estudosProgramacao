#ifndef _PRODUTO_HPP_
#define _PRODUTO_HPP_

#include <string>
#include <iostream>
using namespace std;

class Produto {
    protected: 
        string nome;
        double preco;
        string marca;
        string descricao;
        string dataFabricacao;      

    public:
        string getNome();
        double getPreco();
        string getMarca();
        string getDescricao();  
        string getDataFabricacao();
};

#endif