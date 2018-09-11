#include <iostream> 
#include <time.h>

void sortSelection(int *v, int tam) {
	for(int i = 0; i <tam; i++) {
		int posicaoMenor = i;

		for(int j = i+1; j < tam; j++) {
			if(v[posicaoMenor] > v[j]) {
				posicaoMenor = j;
			}
		}

		int tmp = v[i];
		v[i] = v[posicaoMenor];
		v[posicaoMenor] = tmp;
	}
}


int main() {
	time_t t;
	int tam;
	std::cin >> tam;
	
	int v[tam];

	for(int i = 0; i < tam; i++) {
		std::cin >> v[i];
	}
	
	std::cout << "iniciou\n";

	sortSelection(v, tam);

	t = clock() - t;
	std::cout << "\nTempo de execução: " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	return 0;
}