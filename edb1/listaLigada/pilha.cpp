#include <iostream>

struct node {
    char dado;
    struct node *prox;
};

typedef struct _lista {
    node *inicio;
} lista;

void inserir(lista &seq, char el) {
    node *iter = new node;
    iter->dado = el;
    iter->prox = seq.inicio;
    seq.inicio = iter;
}

int main() {
    lista seq;
    seq.inicio = NULL;
    return 0;
}
