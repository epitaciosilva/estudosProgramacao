#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "../include/midia.hpp"
#include "../include/dvd.hpp"

Dvd::Dvd() { }

Dvd::Dvd(string titulo, string autor, string anoLancamento, string duracao, string classificacao) {
	this->titulo = titulo;
	this->autor = autor;
	this->anoLancamento = anoLancamento;
	this->duracao = duracao;
	this->classificacao = classificacao;
}

Dvd::~Dvd() { }

void operator>> (istream &i, Dvd *dvd) {
	i.ignore();
	cout << "Digite o titulo do DvD: ";
	getline(i, dvd->titulo);

	cout << "Digite o diretor do DvD: ";
	getline(i, dvd->autor);

	cout << "Digite o data de lancamento do DvD: ";
	i >> dvd->anoLancamento;

	i.ignore();
	cout << "Digite a duracao do DvD: ";
	getline(i, dvd->duracao);
	
	cout << "Digite classificacao do DvD: ";
	i >> dvd->classificacao;
}

ostream& operator<< (ostream &o, Dvd &midia) {
	o << "\nTitulo: " << midia.titulo;
	o << "\nAutor: " << midia.autor;
	o << "\nAno de lancamento: " << midia.anoLancamento;
	o << "\nDuracao: " << midia.duracao;
	o << "\nDuracao: " << midia.classificacao;

	return o;
}
