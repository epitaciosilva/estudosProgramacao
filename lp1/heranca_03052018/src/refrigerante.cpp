#include <iostream>
#include <string>
using namespace std;

#include "../include/refrigerante.hpp"

Refrigerante::Refrigerante(){ }

Refrigerante::Refrigerante(string nome, double preco, string marca, string descricao, 
    string dataFabricacao, string dataValidade, string genero, float volume) {

    this->nome = nome;
    this->preco = preco;
    this->marca = marca;
    this->descricao = descricao;
    this->dataFabricacao = dataFabricacao;
    this->dataValidade = dataValidade;
    this->genero = genero;
    this->volume = volume;
    
}

Refrigerante::~Refrigerante(){}