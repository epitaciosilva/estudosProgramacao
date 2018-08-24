#include <iostream>

bool binariaRecursiva(int *v, int chave, int tam) {
	if(tam == 0) {
		return false;
	}
	
	int index = tam/2;

	if(v[index] == chave) {
		return true;
	} else if(v[index] > chave) {
		return binariaRecursiva(v, chave, index);
	} else {
		return binariaRecursiva(&v[index+1], chave, tam-index-1);
	}
}

bool binariaNaoRecursiva(int *v, int chave, int tamanho) {
	int index;
	
	while (tamanho > 0) {
		index = tamanho / 2;
		if (chave == v[index]) { 
			return true; 
		} else if (v[index] > chave) { 
			tamanho = index;
		}else { 
			tamanho = tamanho - index -1; 
			v = &v[index+1];
		}
 	}

	return false;
}

int main() {
	int v[10] = {1,2,3,4,5, 6, 7,8,10,11};
	int num;
	std::cin >> num;
	std::cout << binariaNaoRecursiva(v, num, 10) << std::endl;
	std::cout << binariaRecursiva(v, num, 10) << std::endl;	
	return 0;
}