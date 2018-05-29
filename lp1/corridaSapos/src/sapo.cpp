#include <cstdlib>
#include <iostream>
#include <string>
#include <random>

#include "../include/sapo.h"
int Sapo::distanciaTotal;

std::uniform_int_distribution<> Sapo::distancia(1,100); 


Sapo::Sapo() { }

Sapo::Sapo(
	std::string nome, int identificador, 
	int distanciaPercorrida, int quantidadePulos, 
	int quantidadeCorridas, int vitorias, 
	int empates, int quantidadeTotalPulos
	) {

	this->nome = nome;
	this->identificador = identificador;
	this->distanciaPercorrida = distanciaPercorrida;
	this->quantidadePulos = quantidadePulos;
	this->quantidadeCorridas = quantidadeCorridas;
	this->vitorias = vitorias;
	this->empates = empates;
	this->quantidadeTotalPulos = quantidadeTotalPulos;
	// this->inpulsoMaximo = 
}

Sapo::~Sapo() {}

void Sapo::pular() { 
	// std::srand(std::time(nullptr));
	// distanciaPercorrida += std::rand() % impulsoMaximo + 1;
	// pulos++;
}

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

// int Sapo::getDistanciaTotal() {
// 	return distanciaTotal;
// }

// int Sapo::getDistanciaPercorrida() {
// 	return distanciaPercorrida;
// }