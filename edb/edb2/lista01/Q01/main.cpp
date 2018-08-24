#include <iostream>

#include "../include/pilha.hpp"

int main() {
	Pilha<int> pilha;

	int opcao;

	while(opcao != 0) {
		std::cout 
			<< "1) Empilhar\n" 
			<< "2) Desempilhar\n"
			<< "3) Imprimir lista\n" 
			<< "4) Imprimir menor elemento\n"
			<< "0) Sair\n";
		std::cin >> opcao;

		if(opcao == 1) {
			int num;
			std::cin >> num;
			pilha.empilhar(num);
		} else if(opcao == 2) {
			pilha.desempilhar();
		} else if(opcao == 3) {
			pilha.imprimir();
		} else if(opcao == 4) {
			pilha.imprimirMenorElemento();
		}
	} 
	return 0;
}