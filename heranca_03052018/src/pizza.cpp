#include <iostream>
#include <string>
using namespace std;

#include "../include/pizza.hpp"

Pizza::Pizza(string nome, double preco, string marca, string descricao, 
    string dataFabricacao, string dataValidade, string genero) {

    this->nome = nome;
    this->preco = preco;
    this->marca = marca;
    this->descricao = descricao;
    this->dataFabricacao = dataFabricacao;
}

Pizza::~Pizza(){}
