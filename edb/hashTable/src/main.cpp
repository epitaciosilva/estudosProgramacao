#include <iostream>

#include "../include/hashTable.hpp"

int main() {
    HashTable<int> table;
    int opcao = -1;

    while(opcao != 0) {
        std::cout << "\n1 para adicionar;\n" << "2 para imprimir;\n" << "3 para buscar elemento\n";
        std::cin >> opcao;

        if(opcao == 1) {
            int num; 
            std::cin >> num;

            table.adicionar(num);
        } else if (opcao == 2) {
            std::cout << "\n----Impressão----\n";
            table.imprimir();
        } else if (opcao == 3) {
            int valor;
            std::cin >> valor;

            std::cout << "\n----Busca----\n";
            if(table.busca(valor)) {
                std::cout << "Elemento encontrado\n";
            } else {
                std::cout << "Elemento não encontrado\n";
            }
        }
    } 
    
    return 0;
}