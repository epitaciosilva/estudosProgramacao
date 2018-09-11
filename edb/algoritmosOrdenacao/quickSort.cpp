#include <iostream>
using namespace std;

void quickSort(int *values, int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = values[(began + end) / 2];
	while(i <= j){
		while(values[i] < pivo && i < end){
			i++;
		}
		while(values[j] > pivo && j > began){
			j--;
		}
		if(i <= j){
			aux = values[i];
			values[i] = values[j];
			values[j] = aux;
			i++;
			j--;
		}
	}
	if(j > began) {
		quickSort(values, began, j+1);
	}
	if(i < end) {
		quickSort(values, i, end);
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

    quickSort(v, 0, tam);

    for(int i = 0; i < tam; i++) {
        std::cout << v[i] << std::endl;
    }

    t = clock() - t;
    std::cout << "\nTempo de execução: " << ((float)t)/CLOCKS_PER_SEC << std::endl;

    return 0;
}