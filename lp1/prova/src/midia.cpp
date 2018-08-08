#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#include "../include/midia.hpp"

Midia::Midia() { 

}

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

size_t Midia::buscarMidia(string titulo) {
	for(size_t index = 0; index < this->midias.size(); index++) {
		if(strcmp(midias[index]->titulo.c_str(), titulo.c_str()) == 0) {
			return index;
		}
	}

	return (size_t)-1;
}

void Midia::cadastrarMidia(Midia midia) {
	this->midias.push_back(&midia);

	cout << *this->midias[0] << endl
}

void Midia::removerMidia(string titulo) {
	size_t indexMidia = this->buscarMidia(titulo);

	if(indexMidia > (size_t)-1) {
		this->midias.erase(this->midias.begin()+indexMidia);
		cout << "Midia removida com sucesso!\n";
	} else {
		cout << "\nMidia não encontrada. Tente novamente." << endl;
	}
}

void Midia::atualizarMidia(string titulo) {
	size_t indexMidia = this->buscarMidia(titulo);
	if(indexMidia > (size_t)-1) {
		cout << *this->midias[indexMidia] << endl;
		// cin >> *this->midias[indexMidia];
	} else {
		cout << "\nMidia não encontrada. Tente novamente." << endl;
	}
}

ostream& operator<< (ostream &o, Midia &midia) {
	o << "\nTitulo: " << midia.titulo;
	o << "\nAutor: " << midia.autor;
	o << "\nAno de lancamento: " << midia.anoLancamento;

	return o;
}

