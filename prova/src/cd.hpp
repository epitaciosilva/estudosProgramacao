#include <string>
#include <iostream>
#include <vector>
using namespace std;

Cd::Cd() { }

Cd::~Cd() { }

Cd::Cd(string titulo, string autor, int anoLancamento, int qtdFaixas, string gravadora) {
	this->titulo = titulo;
	this->autor = autor;
	this->anoLancamento = anoLancamento;
	this->qtdFaixas = qtdFaixas;
	this->gravadora = gravadora;
}


Cd::cadastrar() {
	cout << "\nDigite o nome do Cd: ";
	getline(cin, this->titulo);

	cin.ignore();
	cout << "\nDigite o compositor do Cd: ";
	getline(cin, this->autor);

	cout << "\nDigite o data de lancamento do Cd: ";
	cin >> this->anoLancamento;

	cout << "\nDigite o nome da gravadora do Cd: ";
	getline(cin, this->gravadora);
	
	cout << "\nDigite quantidade de faixas do Cd: ";
	cin >> this->qtdFaixas;

	Midia cd = new Cd(this->titulo, this->autor, this->anoLancamento, this->qtdFaixas, this->gravadora);
 
    return cd;	

}

#endif