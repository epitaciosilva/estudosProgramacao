#include <iostream>

/**
* Realiza o merge dos subarrays de v
*/
template <typename T>
void merge(T *v, int l, int half, int r){
    int i, j, k, *w;
    // Cria array para mergear as duas partes do original
    w = new int [r-l];
    // Indexa o pŕoximo elemento do vetor a esquerda
    i = l;
    // Indexa o próximo elemento a direita
    j = half;
    // Indexa a pŕoxima posição de array w
    k = 0;

    while(i < half && j < r){
        if(v[i] <= v[j]){
            w[k++] = v[i++];
        }else{
            w[k++] = v[j++];
        }
    }
    /* Algumas vezes o lado direito ou o lado esquedo
    * não são comparados. Ou seja, é necessário adicionar
    * ao vetor clone os valores restantes do vetor esquerdo
    * ou direito. Isso é feito através desses whiles
    */
    while(i < half){
        w[k++] = v[i++];
    }

    while(j < r){
        w[k++] = v[j++];
    }

    // Adiciona os valores do vetor clone ao original
    for(i = l; i < r; ++i){
        v[i] = w[i-l];
    }

    delete (w);

}

/** Recebe o vetor e os seguintes tamanhos:
* n é o tamanho total do vetor
* l é o index do lado esquerdo (left)
* r é o index do lado direito (right)
*/
template <typename T>
void mergeSort(T *v, int l, int r){
    if(l < r-1){
        int half = (l + r)/2;
        mergeSort(v, l, half);
        mergeSort(v, half, r);
        merge(v, l, half, r);
    }
}

int main(){
    time_t t;
    int tam;
    std::cin >> tam;
    
    int v[tam];

    for(int i = 0; i < tam; i++) {
        std::cin >> v[i];
    }
    
    std::cout << "iniciou\n";

    mergeSort(v, 0, tam);

    for(int i = 0; i < tam; i++) {
        std::cout << v[i] << std::endl;
    }

    t = clock() - t;
    std::cout << "\nTempo de execução: " << ((float)t)/CLOCKS_PER_SEC << std::endl;

    return 0;
}