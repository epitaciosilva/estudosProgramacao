#include <iostream>
#include <string>
using namespace std;

#include "../include/produto.hpp"

void Produto::setNome(string nome) {
    this->nome = nome;
}

void Produto::setPreco(double preco) {
    this->preco = preco;
}

void Produto::setMarca(string marca) {
    this->marca = marca;
}

void Produto::setDescricao(string descricao)  {
    this->descricao = descricao;
}

void Produto::setDataFabricacao(string dataFabricacao) {
    this->dataFabricacao = dataFabricacao;
}

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