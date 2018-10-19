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
    // std::cin >> option;
    // std::cout << (arvore.busca(option) != -1 ? "true" : "false") << '\n';
}