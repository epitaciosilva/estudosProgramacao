#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "../include/midia.hpp"
#include "../include/livro.hpp"

Livro::Livro() { }

Livro::Livro(string titulo, string autor, string anoLancamento, string editora, string isbn) { 
	this->titulo = titulo;
	this->autor = autor;
	this->anoLancamento = anoLancamento;
	this->editora = editora;
	this->isbn = isbn;
}

Livro::~Livro() { }

void operator>> (istream &i, Livro &livro) {
	i.ignore();
	
	cout << "Digite o titulo do livro: ";
	getline(i, livro.titulo);

	cout << "Digite o autor do livro: ";
	getline(i, livro.autor);
	
	cout << "Digite a data de lancamento do livro: ";
	i >> livro.anoLancamento;

	i.ignore();
	cout << "Digite o editora do livro: ";
	getline(i, livro.editora);
}

