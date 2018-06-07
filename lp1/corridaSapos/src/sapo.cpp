#include <iostream>
#include <string>
#include <random>

#include "../include/sapo.hpp"
// int Sapo::distanciaTotal;

std::random_device Sapo::rd{};
std::mt19937 Sapo::gen(Sapo::rd());
std::uniform_int_distribution<> Sapo::dis(1,100);

Sapo::Sapo() { }

Sapo::Sapo(std::string descricao, std::string identificador) {
	this->descricao = descricao;
	this->identificador = identificador;
	this->distanciaPercorrida = 0;
	this->quantidadePulos = 0;
	this->quantidadeCorridas = 0;
	this->vitorias = 0;
	this->empates = 0;
	this->quantidadeTotalPulos = 0;
	this->impulsoMaximo = std::round(dis(gen));
}

Sapo::~Sapo() {}

void Sapo::setDistanciaPercorrida(int distanciaPercorrida) {
	this->distanciaPercorrida += distanciaPercorrida;
}

void Sapo::posCorrida(bool vitoria, bool empate) {
	this->quantidadeCorridas++;

	if(vitoria) {
		this->vitorias++;
	} else if(empate) {
		this->empates++;
	}
}

void Sapo::pular() { 
	std::uniform_int_distribution<int> distribution(1, this->impulsoMaximo);
	this->distanciaPercorrida += std::round(distribution(gen));
	quantidadePulos++;
}

int Sapo::getDistanciaPercorrida() {
	return this->distanciaPercorrida;
}

std::string Sapo::getIdentificador() {
	return this->identificador;
}

std::string Sapo::getDescricao() {
	return this->descricao;
}

// void Sapo::setDescricao(std::string descricao) {
// 	this->descricao = descricao;
// }

// void Sapo::setIdentificador(std::string identificador) {
// 	this->identificador = identificador;
// }