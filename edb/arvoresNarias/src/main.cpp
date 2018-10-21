#include <iostream>

#include "../include/arvoreComNos.hpp"

int main() {
    ArvoreComNos<int> arvore(2);
    int option = 0;
    std::cin >> option;

    while(option != -1) {
        arvore.addElemento(option);
        std::cin >> option;
    }
    arvore.print();
    std::cin >> option;

    while(option != -1) {
        std::cout << '\n' << (arvore.busca(option) != NULL ? "true" : "false") << '\n';
        std::cin >> option;
    }

    arvore.print();
    std::cin >> option;

    while(option != -1) {
        arvore.remover(option);
        arvore.print();
        std::cin >> option;
    }
}