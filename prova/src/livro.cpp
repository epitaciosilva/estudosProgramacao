#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "../include/midia.hpp"
#include "../include/livro.hpp"

Livro::Livro() { }

Livro::Livro(string titulo, string autor, int anoLancamento, string editora, string isbn) { 
	this->titulo = titulo;
	this->autor = autor;
	this->anoLancamento = anoLancamento;
	this->editora = editora;
	this->isbn = isbn;
}

Livro::~Livro() { }

void operator>> (istream &i, Livro &livro) {
	cout << "\nDigite o titulo do livro: ";
	getline(i, livro.titulo);

	i.ignore();
	cout << "\nDigite o autor do livro: ";
	getline(i, livro.autor);
	
	cout << "\nDigite a data de lancamento do livro: ";
	i >> livro.anoLancamento;

	cout << "\nDigite o editora do livro: ";
	getline(i, livro.editora);

}

