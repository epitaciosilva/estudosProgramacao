#include <string>
#include <iostream>
#include <vector>
using namespace std;

Livro::Livro() { }


Livro::Livro(string titulo, string autor, int anoLancamento, string editora, string isbn) { 
	this->titulo = titulo;
	this->autor = autor;
	this->anoLancamento = anoLancamento;
	this->editora = editora;
	this->isbn = isbn;
}

Livro::~Livro() { }

Midia Livro::cadastrar() {
	cout << "\nDigite o titulo do livro: ";
	getline(cin, this->titulo);

	cin.ignore();
	cout << "\nDigite o autor do livro: ";
	getline(cin, this->autor);
	
	cout << "\nDigite a data de lancamento do livro: ";
	cin >> this->anoLancamento;

	cout << "\nDigite o editora do livro: ";
	getline(cin, this->editora);


	Midia livro = new Livro(titulo, autor, editora, anoLancamento);
 
    return livro;	
}

#endif