#include <iostream>
#include <string>
#include <random>

#include "../include/sapo.hpp"
// int Sapo::distanciaTotal;

std::random_device Sapo::rd{};
std::mt19937 Sapo::gen(Sapo::rd());
std::uniform_int_distribution<> Sapo::dis(1,100);

Sapo::Sapo() { }

Sapo::Sapo(std::string nome, int identificador) {

	this->nome = nome;
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

int Sapo::getIdentificador() {
	return this->identificador;
}

// Sapo::setQuantidadeCorridas() {
// 	this->quantidadeCorridas++;
// }

// Sapo::setVitorias() {
// 	this->vitorias++;
// }

// Sapo::setEmpates() {
// 	this->empates++;
// }

// int Sapo::getIdentificador() {
// 	return identificador;
// }

// void Sapo::setIdentificador(int ident) {
// 	identificador = ident;
// }

// int Sapo::getImpulsoMaximo() {
// 	return impulsoMaximo;
// }

// void Sapo::setImpulsoMaximo(int impulso){
// 	impulsoMaximo = impulso;
// }

// int Sapo::getPulos() {
// 	return pulos;
// }


// int Sapo::getDistanciaPercorrida() {
// 	return distanciaPercorrida;
// }