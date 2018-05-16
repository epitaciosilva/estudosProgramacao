#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "../include/midia.hpp"
#include "../include/cd.hpp"

Cd::Cd() { }

Cd::~Cd() { }

Cd::Cd(string titulo, string autor, int anoLancamento, int qtdFaixas, string gravadora) {
	this->titulo = titulo;
	this->autor = autor;
	this->anoLancamento = anoLancamento;
	this->qtdFaixas = qtdFaixas;
	this->gravadora = gravadora;
}

void operator>> (istream &i, Cd &cd) { 
	cout << "\nDigite o nome do Cd: ";
	getline(i, cd.titulo);

	i.ignore();
	cout << "\nDigite o compositor do Cd: ";
	getline(i, cd.autor);

	cout << "\nDigite o data de lancamento do Cd: ";
	i >> cd.anoLancamento;

	cout << "\nDigite o nome da gravadora do Cd: ";
	getline(i, cd.gravadora);
	
	cout << "\nDigite quantidade de faixas do Cd: ";
	i >> cd.qtdFaixas;
}

