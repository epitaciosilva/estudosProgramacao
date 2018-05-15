#include <string>
#include <iostream>
#include <vector>
using namespace std;

Dvd::Dvd() { }

Dvd::Dvd(string titulo, string autor, int anoLancamento, string duracao, string classficacao) {
	this->titulo = titulo;
	this->autor = autor;
	this->anoLancamento = anoLancamento;
	this->duracao = duracao;
	this->classficacao = classficacao;
}

Dvd::~Dvd() { }

Midia Dvd::cadastrar() {
	cout << "\nDigite o titulo do DvD: ";
	getline(cin, this->titulo);

	cin.ignore();
	cout << "\nDigite o diretor do DvD: ";
	getline(cin, this->autor);

	cout << "\nDigite o data de lancamento do DvD: ";
	cin >> this->anoLancamento;

	cout << "\nDigite a duracao do DvD: ";
	getline(cin, this->duracao);
	
	cout << "\nDigite classificacao do DvD: ";
	cin >> this->classificacao;

	Midia dvd = new Dvd(this->titulo, this->autor, this->anoLancamento, this->duracao, this->classficacao);
 
    return dvd;	
}

#endif