#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "../include/conta.hpp"
#include "../include/movimentacao.hpp"	

int main() { 
	Conta c1("12345", "54321", 1000.0);
	c1.deposito(1000.0);
	c1.saque(1001.0);

	Conta c2("54321", "5321", 1000.0);
	c2.deposito(1000.0);
	c2.saque(100.0);

	c1.transferencia(c2, 200.0);
	return 0;
}