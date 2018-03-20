#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "sapo.h"
int Sapo::distanciaTotal;
 
Sapo::Sapo() {
	identificador = 0;
	distancia = 0;
	pulos = 0;
}

Sapo::Sapo(int ident, int dist) {
	identificador = ident;
	distancia = dist;
	pulos = 0;
}

Sapo::~Sapo() {}

int Sapo::getIdentificador() {
	return identificador;
}

void Sapo::setIdentificador(int ident) {
	identificador = ident;
}

int Sapo::getDistancia() {
	return distancia;
}

void Sapo::setDistancia(int dist){
	distancia = dist;
}

int Sapo::getPulos() {
	return pulos;
}

int Sapo::getDistanciaTotal() {
	return distanciaTotal;
}

int Sapo::pular() { 
	std::srand(std::time(nullptr));

	int distanciaPercorrida = std::rand() % distancia + 1;
	pulos++;
	
	return distanciaPercorrida;
}