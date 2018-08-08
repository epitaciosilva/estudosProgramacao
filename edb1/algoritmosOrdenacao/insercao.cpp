#include <iostream>
using namespace std;

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
    int v[4] = {10, 8, 9, 5};
    sortInsercao(v, 4);
}