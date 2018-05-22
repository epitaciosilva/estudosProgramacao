#include <iostream>
#include <string>
using namespace std;

#include "../include/produto.hpp"

string Produto::getNome() {
    return this->nome;
}

double Produto::getPreco(){
    return this->preco;
}

string Produto::getMarca(){
    return this->marca;
}

string Produto::getDescricao(){
    return this->descricao;
}  

string Produto::getDataFabricacao(){
    return this->dataFabricacao;
}