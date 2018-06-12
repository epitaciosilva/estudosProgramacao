#include "../include/cache.hpp"

Cache::Cache() {
	this->linha = 0;
	this->bloco = 0;
	this->endereco = 0;
	this->conteudo = 0;
	this->contadorUtilizado = 0;
	this->contadorTemporal = 0;
}

Cache::~Cache() { }