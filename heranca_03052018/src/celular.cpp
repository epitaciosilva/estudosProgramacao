#include <iostream>
#include <string>
using namespace std;

#include "../include/celular.hpp"

Celular::Celular(string nome, double preco, string marca, string descricao, string dataFabricacao, 
    string materialPredominante, int durabilidade) {
    this->nome = nome;
    this->preco = preco;
    this->marca = marca;
    this->descricao = descricao;
    this->dataFabricacao = dataFabricacao;
    this->materialPredominante = materialPredominante;
    this->durabilidade = durabilidade;
}

Celular::~Celular(){}
