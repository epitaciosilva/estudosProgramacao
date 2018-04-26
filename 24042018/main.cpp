#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "lista.hpp"

int main() {
	Lista<int> lista;
	lista.addValue(10);
	lista.addValue(20);
	lista.addValue(5);
	lista.showAll();
	lista.exclude(10);
	lista.showAll();
	lista.showSigle(20);

	Lista<float> lista2;
	lista2.addValue(10.3);
	lista2.addValue(20.2);
	lista2.addValue(5.2);
	lista2.showAll();
	lista2.exclude(10.1);
	lista2.showAll();
	lista2.showSigle(20.1);
	return 0;
}
