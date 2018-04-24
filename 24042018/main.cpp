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
	lista.show();
	
	return 0;
}