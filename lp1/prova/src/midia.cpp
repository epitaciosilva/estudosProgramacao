#include <string>
#include <iostream>
#include <vector>
#include <cstring>
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

void operator>> (istream &i, Midia &midia) {
	i.ignore();
	cout << "Digite o titulo do DvD: ";
	getline(i, midia.titulo);

	cout << "Digite o diretor do DvD: ";
	getline(i, midia.autor);

	cout << "Digite o data de lancamento do DvD: ";
	i >> midia.anoLancamento;
}

void Midia::cadastrarMidia(Midia midia) {
	std::cin >> midia;
	this->midias.push_back(midia);
}

void Midia::removerMidia(string titulo) {
	for(size_t i = 0; i < this->midias.size(); i++){
		if(strcmp(midias[i].titulo.c_str(), titulo.c_str()) == 0) {
			this->midias.erase(this->midias.begin()+i);
			cout << midias.size() << endl;
			return;
		}
	}

	cout << "Midia não encontrada. Tente novamente.";
}

