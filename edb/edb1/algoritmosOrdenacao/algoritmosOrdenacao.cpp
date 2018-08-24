#include <iostream>
using namespace std;

void sortSelecao(int *v, int N) {
    for(int i = 0; i < N; i++) {
        int posicaoMenor = i;
        for(int j = i+1; j < N; j++) {
            if(v[posicaoMenor] > v[j]) {
                posicaoMenor = j;
            }
        }

        int tmp = v[i];
        v[i] = v[posicaoMenor];
        v[posicaoMenor] = tmp;       
    }
    for(int n = 0; n < N; n++) { 
        cout << v[n] << " ";
    }
    cout << endl; 
}

void sortInsercao(int *v, int N) {
    for(int i = 0; i < N; i++) {
        int numero = v[i];
        int posicaoInsercao = i;

        while(posicaoInsercao > 0 && v[posicaoInsercao-1]>numero) {
            v[posicaoInsercao] = v[posicaoInsercao-1];
            posicaoInsercao--;            
        }
        v[posicaoInsercao] = numero; 
    }
    
    for(int j = 0; j < N; j++) { 
        cout << v[j] << " ";
    }
    cout << endl;
}

int main() {
    int v[4] = {10, 6, 5, 1};
    sortSelecao(v, 4);
	sortInsercao(v, 4);
}
