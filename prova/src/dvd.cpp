#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "../include/midia.hpp"
#include "../include/dvd.hpp"

Dvd::Dvd() { }

Dvd::Dvd(string titulo, string autor, int anoLancamento, string duracao, string classificacao) {
	this->titulo = titulo;
	this->autor = autor;
	this->anoLancamento = anoLancamento;
	this->duracao = duracao;
	this->classificacao = classificacao;
}

Dvd::~Dvd() { }

void operator>> (istream &i, Dvd &dvd) {
	cout << "\nDigite o titulo do DvD: ";
	getline(i, dvd.titulo);

	i.ignore();
	cout << "\nDigite o diretor do DvD: ";
	getline(i, dvd.autor);

	cout << "\nDigite o data de lancamento do DvD: ";
	i >> dvd.anoLancamento;

	cout << "\nDigite a duracao do DvD: ";
	getline(i, dvd.duracao);
	
	cout << "\nDigite classificacao do DvD: ";
	i >> dvd.classificacao;
}

