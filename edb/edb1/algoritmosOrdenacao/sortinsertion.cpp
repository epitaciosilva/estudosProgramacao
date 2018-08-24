#include <iostream> 
#include <time.h>

bool sortInsertion(int *v, int tamanho) {
	for(int i = 0; i < tamanho; i++) {
		int numTemp = v[i];
        int posicaoInsercao = i;

		while(posicaoInsercao > 0 && v[posicaoInsercao-1] > numTemp) {
			v[posicaoInsercao] = v[posicaoInsercao-1];
        	posicaoInsercao--;
		}

        v[posicaoInsercao] = numTemp; 
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

	sortInsertion(v, tam);

	for(int i = 0; i < tam; i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	t = clock() - t;
	std::cout << "\nTempo de execução: " << ((float)t)/CLOCKS_PER_SEC << std::endl;

	return 0;
}