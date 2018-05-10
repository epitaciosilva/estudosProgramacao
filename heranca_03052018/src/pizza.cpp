#include <iostream>
#include <string>
using namespace std;

#include "../include/pizza.hpp"


Pizza::Pizza(){ }

Pizza::Pizza(string nome, double preco, string marca, string descricao, 
    string dataFabricacao, string dataValidade, string genero, string sabor) {

    this->nome = nome;
    this->preco = preco;
    this->marca = marca;
    this->descricao = descricao;
    this->dataFabricacao = dataFabricacao;
    this->dataValidade = dataValidade;
    this->genero = genero;
    this->sabor = sabor;
    
}

Pizza::~Pizza(){}