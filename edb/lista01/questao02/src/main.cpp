#include <iostream>

#include "../include/conjuntoDePilhas.hpp"

int main() {
	ConjuntoDePilhas<int> pilhas;

	int opcao;
	while(opcao != 0) {
		std::cout 
			<< "\n1) Empilhar\n" 
			<< "2) Desempilhar\n"
			<< "3) Imprimir lista\n" 
			<< "0) Sair\n";
		std::cin >> opcao;

		if(opcao == 1) {
			int num;
			std::cin >> num;
			pilhas.empilhar(num);
		} else if(opcao == 2) {
			pilhas.desempilhar();
		} else if(opcao == 3) {
			pilhas.imprimir();
		}
	} 
	return 0;
}