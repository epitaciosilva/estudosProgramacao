#include <iostream>

bool buscaLinearRecursiva(int *v, int chave, int tamanho) {
	for(int i = 0; i < tamanho; i++) {
		if(v[i] == chave) {
			return true;
		}
	}

	return false;
}

int main() {
	int v[10] = {1,2,3,4,5, 6, 7,8,10,11};
	int num;
	std::cin >> num;
	std::cout << buscaLinearRecursiva(v, num, 10) << std::endl;
	return 0; 
}