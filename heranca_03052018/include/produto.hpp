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
        void setNome(string nome);
        void setPreco(double preco);
        void setMarca(string marca);
        void setDescricao(string descricao);  
        void setDataFabricacao(string dataFabricacao);
        string getNome();
        double getPreco();
        string getMarca();
        string getDescricao();  
        string getDataFabricacao();
};

#endif