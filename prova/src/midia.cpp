#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "../include/midia.hpp"

Midia::Midia() { }

Midia::~Midia() { }

void Midia::listarTodasMidias() {
	for(size_t i = 0; i < this->midias.size(); i++) {
		cout << midias[i];
	}
}

void Midia::listarQtdMidiasPorTipo() {
	for(size_t i = 0; i < this->midias.size(); i++) {
		
	}
}

ostream& operator<< (ostream &o, Midia &midia) {
	o << "\nTitulo: " << midia.titulo;
	o << "\nAutor: " << midia.autor;
	o << "\nAno de lancamento: " << midia.anoLancamento;

	return o;
}

void Midia::cadastrarMidia(Midia midia) {
	this->midias.push_back(midia);
}

