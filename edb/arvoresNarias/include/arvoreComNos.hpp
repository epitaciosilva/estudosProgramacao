#ifndef _ARVORE_HPP_
#define _ARVORE_HPP_

#include <vector>
#include "./node.hpp"

template <typename T>
class ArvoreComNos {
    private:
        Node<T> *raiz;
        int N;

	public:
		ArvoreComNos(int N) { 
            this->raiz = NULL;
            this->N = N;
        }
        
        void adicionar(Node<T> *no, Node<T> *tmp) {
            if(no->getQuantidadeFilhos() < this->N) {
                no->adicionarFilho(tmp);
            } else {
                for(int i =0; i < this->N; i++) { 
                    if(no->filhos[i]->getQuantidadeFilhos() < this->N) {
                        adicionar(no->filhos[i], tmp);
                        break;
                    } else if(i == this->N-1){
                        // se estiver cheia adiciona no primeiro elemento
                        adicionar(no->filhos[0], tmp);
                    }
                }
            }
        }

        void adicionar(T valor) {
            Node<T> *tmp = new Node<T>(valor);
            
            if(this->raiz == NULL) {
                this->raiz = tmp;
            } else {
                this->adicionar(this->raiz, tmp);
            }
        }
        
        Node<T>* busca(Node<T>* node, T valor) {
            Node<T>* elemento = NULL;

            if(node->valor == valor) {
                return node;
            } else {
                for(int i =0; i < node->getQuantidadeFilhos(); i++) { 
                    if(node->filhos[i] != NULL) {
                        // busca recursivamente através profundidade primeiramente 
                        elemento = busca(node->filhos[i], valor);
                        if(elemento != NULL) {
                            return elemento;
                        }
                    }
                }
            }

            return elemento;
        }

        Node<T>* busca(T valor) {
            if(this->raiz == NULL) {
                return NULL;
            }
            return this->busca(this->raiz, valor);
        }

        void remover(T valor) {
            // buscando o elemento
            Node<T> *tmp = this->busca(valor);

            if(tmp == NULL) {
                std::cout << "Elemento não encontrado\n";
            } else if(tmp->pai != NULL) {
                tmp->pai->removerFilho(tmp->posicaoVetorDoPai);
                this->removerRecursivamente(tmp);
            } else {
                // só ocorre se for pra remover a raiz
                this->removerRecursivamente(tmp);
                this->raiz = NULL;
            }
        }

        void removerRecursivamente(Node<T> *tmp) {
            for(int i =0; i < tmp->getQuantidadeFilhos(); i++) {
                this->removerRecursivamente(tmp->filhos[i]);
            }

            // removendo todos os filhos do vetor
            tmp->removerFilhos();
            delete tmp;
        }

        void altura() {
            std::cout << "Altura: " << this->altura(this->raiz) << '\n';
        }

        int altura(Node<T>* tmp) {
            int n = 1;
            
            if(tmp == NULL) {
                return 0;
            } else if(tmp->getQuantidadeFilhos() > 0) {
                // isso funciona pq a inserção no momento que a árvore está cheia
                // é no primeiro filho. 
                // Por isso só precisa percorrer a profundidade no primeiro filho recursivamente
                n += altura(tmp->filhos[0]);
            }

            return n;
        }

        void printFilhos(Node<T> *tmp) {
            for(int i = 0; i < tmp->getQuantidadeFilhos(); i++) {
                std::cout << tmp->filhos[i]->valor << " ";
            }
            std::cout << " ";
        }

        void printAll(Node<T> *tmp) {
            this->printFilhos(tmp);
            std::cout << '\n';
            for(int i = 0; i < tmp->getQuantidadeFilhos(); i++) {
                this->printFilhos(tmp->filhos[i]);
            }
            std::cout << '\n';
        }

        void print() {
            std::cout << "\n----Árvore----\n";
            if(this->raiz == NULL) {
                std::cout << "Árvore vazia\n";
            } else {
                std::cout << this->raiz->valor << '\n';
                this->printAll(this->raiz);
            }
        }
};

#endif