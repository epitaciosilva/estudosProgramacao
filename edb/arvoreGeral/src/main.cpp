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

    std::cin >> valor;
    do {
        if(arvore.buscar(valor)) {
            std::cout << "Está\n";
        } else {
            std::cout << "Não está\n";
        }
        std::cin >> valor;
    } while(valor != -1);
    
    return 0;
}