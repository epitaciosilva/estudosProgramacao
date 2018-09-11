#include "iostream"
#include "listaDuplamenteLigada.hpp"

int main() {
    ListaDuplamenteLigada<int> lista;

    lista.push_front(1);
    lista.push_front(1);
    lista.push_front(1);
    lista.push_front(1);
    lista.push_front(1);
    lista.print();
    return 0;
}