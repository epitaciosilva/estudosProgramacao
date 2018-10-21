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
        
        void add(Node<T> *no, Node<T> *tmp) {
            if(no->quantidadeFilhos() < this->N) {
                no->addFilho(tmp);
            } else {
                for(int i =0; i < this->N; i++) { 
                    if(no->filhos[i]->quantidadeFilhos() < this->N) {
                        add(no->filhos[i], tmp);
                        break;
                    } else if(i == this->N-1){
                        add(no->filhos[0], tmp);
                    }
                }
            }
        }

        void addElemento(T valor) {
            Node<T> *tmp = new Node<T>(valor);
            
            if(this->raiz == NULL) {
                this->raiz = tmp;
            } else {
                this->add(this->raiz, tmp);
            }
        }
        
        Node<T>* buscaNo(Node<T>* tmp, T valor) {
            Node<T>* elemento = NULL;
            if(tmp->valor == valor) {
                return tmp;
            } else {
                for(int i =0; i < tmp->quantidadeFilhos(); i++) { 
                    if(tmp->filhos[i] != NULL) {
                        elemento = buscaNo(tmp->filhos[i], valor);
                        if(elemento != NULL) {
                            return elemento;
                        }
                    }
                }                
            }

            return elemento;
        }

        Node<T>* busca(T valor) {
            return this->buscaNo(this->raiz, valor);
        }

        void remover(T valor) {
            Node<T> *tmp = this->busca(valor);
            tmp->pai->removerFilhos(tmp->posicaoVetorDoPai);
            this->removerRecursivamente(tmp);
        }

        void removerRecursivamente(Node<T> *tmp) {
            for(int i =0; i < tmp->quantidadeFilhos(); i++) {
                this->removerRecursivamente(tmp->filhos[i]);
            }
            // removendo todos os filhos do vetor
            tmp->removerFilhos();
            delete tmp;
        }
 
       // precisa ser melhorado
        void printNo(Node<T> *tmp) {
            for(int i =0; i < tmp->quantidadeFilhos(); i++) {
                std::cout << tmp->filhos[i]->valor << " ";
                if(tmp->filhos[i]->quantidadeFilhos() != 0) {
                    printNo(tmp->filhos[i]);
                }
            }

            std::cout << '\n';
        }

        void print() {
            std::cout << "\n----Árvore----\n";
            std::cout << this->raiz->valor << '\n';
            this->printNo(this->raiz);
        }
};

#endif