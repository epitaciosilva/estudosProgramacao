#include <iostream>

struct node {
    char dado;
    struct node *prox;
};

typedef struct _lista {
    node *inicio;
} lista;

void inserir(lista &seq, char el) {
    if(seq.inicio == NULL) {
        node *temp = new node;
        temp->prox = NULL;
        temp->dado = el;
        seq.inicio = temp;
    } else {
        node *iter = seq.inicio;
        while(iter->prox) {
            iter = iter->prox;
        }
        node *temp = new node;
        temp->prox = NULL;
        temp->dado = el;
        iter->prox = temp;
    }
}

void remover(lista &seq) {
    node *iter = seq.inicio;
    if(iter->prox == NULL) {
        delete iter;
        seq.inicio = NULL;
        return;
    }
    while(iter->prox->prox) {
        iter = iter->prox;
    }
    delete iter->prox;
    iter->prox = NULL;
}

void imprimir(lista &seq) {
    node *iter = seq.inicio;
    std::cout << "[";
    while(iter) {
        std::cout << iter->dado << " ";
        iter = iter->prox;
    }
    std::cout << "]";
}

int main() {
    lista seq;
    seq.inicio = NULL;
    std::cout << std::endl;
    inserir(seq, 'A');
    inserir(seq, 'B');
    inserir(seq, 'C');
    inserir(seq, 'D');
    imprimir(seq);
    remover(seq);
    remover(seq);
    remover(seq);
    remover(seq);
    std::cout << std::endl;
    imprimir(seq);
    std::cout << std::endl;
    return 0;
}
