#include <iostream>
using namespace std;

#include "lista.hpp"

template<class Tipo>
Lista<Tipo>::Lista() {}

// template<class Tipo>
// vector<Tipo> Lista<Tipo>::criarLista() {
// 	return vector<Tipo> lista;
// }
// template<class Tipo>
// int Lista<Tipo>::buscar(Tipo tipo) {
// 	for(int i = 0; this->lista.size(); i++) {
// 		if(this->lista[i] == tipo) {
// 			return i;
// 		}
// 	}
// }

template<class Tipo>
void Lista<Tipo>::addValue(Tipo value) {
	this->lista.push_back(value);
}