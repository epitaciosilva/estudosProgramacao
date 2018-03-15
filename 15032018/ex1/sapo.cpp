#include <cstdlib>
#include <iostream>
#include <ctime>

#include "sapo.cpp"

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,6);

int Sapo::distanciaTotal;
Sapo::Sapo(){
	identificador = 0;
	distancia = 0;
	pulos = 0;
}
 
Sapo::Sapo(int idt, int dtc, int pul){
	identificador = idt;
	distancia = dtc;
	pulos = pul;
}

Sapo::~Sapo() {
	//Desconstrutor
}

int pular() {
	std::srand(std::time(nullptr));
	int distanciaPercorrida = std::rand() % distancia + 1;

	return 
}


int Sapo::getIdentificador() {
	return lado;
}

void Sapo::setIdentificador(int idt){
	identificador = idt;
}

int Sapo::getDistancia() {
	return distancia;
}

void Sapo::setDistancia(int dtc){
	distancia = dtc;
}

int Sapo::getPulos() {
	return pulos;
}

void Sapo::setPulos(int pul){
	pulos = pul;
}

int getDistanciaTotal() {
	return distanciaTotal;
}