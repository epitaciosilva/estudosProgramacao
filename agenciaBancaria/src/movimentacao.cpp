#include <iostream>
#include <sstream>
#include <string>

#include "../include/movimentacao.hpp"

Movimentacao::Movimentacao(string descricao, double valor, string indicacao) {
	this->descricao = descricao;
	this->valor = valor;
	this->indicacao = indicacao;
}


string Movimentacao::getDescricao() {
	return this->descricao;
}
