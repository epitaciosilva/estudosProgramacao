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
    int v[10] = {5, 3, 1, 2, 8, 9, 10, 7, 6, 4};
    quickSort(v, 0, 10);

    for(int j = 0; j < 10; j++) { 
        cout << v[j] << " ";
    }
    cout << endl;
}