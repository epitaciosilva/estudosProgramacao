#include <iostream>

#include "../include/arvore.hpp"

int main() {
    Arvore<int> arvore;

    int valor;
    std::cin >> valor;

    do {
        arvore.adicionar(valor);
        std::cin >> valor;
    } while(valor != -1);

    arvore.print();
    return 0;
}