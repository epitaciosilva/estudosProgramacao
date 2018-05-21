#include <iostream>
#include <string>
using namespace std;

#include "../include/carro.hpp"

Carro::Carro(string nome, double preco, string marca, string descricao, string dataFabricacao, 
    string materialPredominante, int durabilidade, int qtdPortas, string cor) {

    this->nome = nome;
    this->preco = preco;
    this->marca = marca;
    this->descricao = descricao;
    this->dataFabricacao = dataFabricacao;
    this->materialPredominante = materialPredominante;
    this->durabilidade = durabilidade;
    this->qtdPortas = qtdPortas;
    this->cor = cor;
    
}

Carro::~Carro(){}

int Carro::getQtdPortas() {
    return this->qtdPortas;
}

string Carro::getCor() {
    return this->cor;
}