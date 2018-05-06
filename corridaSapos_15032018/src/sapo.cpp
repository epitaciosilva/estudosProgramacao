#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "../include/sapo.h"
int Sapo::distanciaTotal;
 
Sapo::Sapo() {
	identificador = 0;
	impulsoMaximo = 0;
	pulos = 0;
}

Sapo::Sapo(int ident, int impulso) {
	identificador = ident;
	impulsoMaximo = impulso;
	pulos = 0;
	distanciaPercorrida = 0;
}

Sapo::~Sapo() {}

int Sapo::getIdentificador() {
	return identificador;
}

void Sapo::setIdentificador(int ident) {
	identificador = ident;
}

int Sapo::getImpulsoMaximo() {
	return impulsoMaximo;
}

void Sapo::setImpulsoMaximo(int impulso){
	impulsoMaximo = impulso;
}

int Sapo::getPulos() {
	return pulos;
}

int Sapo::getDistanciaTotal() {
	return distanciaTotal;
}

int Sapo::getDistanciaPercorrida() {
	return distanciaPercorrida;
}

void Sapo::pular() { 
	std::srand(std::time(nullptr));
	distanciaPercorrida += std::rand() % impulsoMaximo + 1;
	pulos++;
}