#include <iostream>
#include <string>
using namespace std;

#include "../include/livro.hpp"

Livro::Livro(string nome, double preco, string marca, string descricao, string dataFabricacao, 
    string materialPredominante, int durabilidade, int qtdPaginas) {

    this->nome = nome;
    this->preco = preco;
    this->marca = marca;
    this->descricao = descricao;
    this->dataFabricacao = dataFabricacao;
    this->materialPredominante = materialPredominante;
    this->durabilidade = durabilidade;
    this->qtdPaginas = qtdPaginas;
}

Livro::~Livro(){}

int Livro::getQtdPaginas() {
    return this->qtdPaginas;
}
