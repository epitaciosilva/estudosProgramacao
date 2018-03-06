#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "fatorial.h"
#include "primalidade.h"

int main() {
	int num;
	int fat;
	int primo;

	cin >> num;

	fat = fatorial(num);
	primo = maiorPrimo(fat);
	cout << primo << endl;

	return 0;
}