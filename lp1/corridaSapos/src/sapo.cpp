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
	//Zera a distancia e a quantidade de pulos para não interferir na próxima corrida.
	this->distanciaPercorrida = 0;
	this->quantidadePulos = 0;

	//Aumenta ao termino de cada corrida.
	this->quantidadeCorridas++;
	
	//Adicionando vitorias e empates.
	if(vitoria) {
		this->vitorias++;
	} 
	if(empate) {
		this->empates++;
	}
}

void Sapo::pular() { 
	
	std::uniform_int_distribution<int> distribution(1, this->impulsoMaximo);
	int pulo = std::round(distribution(gen));
	
	//Incrementa a distancia percorrida pelo sapo na corrida.
	this->distanciaPercorrida += pulo;
	//Aumenta a quantidade de pulos.
	quantidadePulos++;
	quantidadeTotalPulos++;

	//Imprime as informações do sapo e o pulo dado.
	std::cout << "\nSapo: " << this->descricao << std::endl;
	std::cout << "Identificador: " << this->identificador << std::endl;
	std::cout << "Pulo: " << pulo << std::endl;
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

int Sapo::getQuantidadePulos() {
	return this->quantidadePulos;
}