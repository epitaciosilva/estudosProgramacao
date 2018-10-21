#include <iostream>

#include "../include/arvoreComNos.hpp"

int main() {
    int N;
    std::cout << "Insira o valor de N da árvore: ";
    std::cin >> N;
    ArvoreComNos<int> arvore(N);
    int option = 0;

    do {
        std::cout << "\n1 para inserir;\n"
                << "2 para buscar;\n"
                << "3 para remover;\n"
                << "4 para imprimir;\n" 
                << "0 para sair;\n";
        std::cin >> option;

        if(option >= 1 && option <=3) {
            int elemento;
            std::cin >> elemento;

            if(option == 1) {
                arvore.addElemento(elemento);
            } else if(option == 2) {
                std::cout << (arvore.busca(elemento) != NULL ? "Está" : "Não está") << " na árvore\n";
            } else {
                arvore.remover(elemento);
            }
        } else if(option == 4) {
            arvore.print();
        }
    } while(option != 0);
}