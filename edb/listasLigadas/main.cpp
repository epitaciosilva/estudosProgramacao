#include "iostream"
#include "listaDuplamenteLigada.hpp"

int main() {
    ListaDuplamenteLigada<int> lista1,lista2;

    lista1.push_back(1);
    lista1.push_back(2);
    lista1.push_back(3);
    lista1.push_back(4);
    lista1.push_back(5);

    lista2.push_back(6);
    lista2.push_back(7);
    lista2.push_back(8);
    lista2.push_back(9);
    lista2.push_back(10);
    lista2.merge(&lista1);
    lista2.print();
    return 0;
}