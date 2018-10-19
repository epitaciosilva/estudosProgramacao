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
        
        void add(Node<T> *raiz, Node<T> *tmp) {
            if(raiz->filhos.size() < (size_t) this->N) {
                raiz->addFilho(tmp);
            } else {
                add(raiz->filhos[0], tmp);
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
            Node<T>* elem = NULL;
            if(tmp->valor == valor) {
                return tmp;
            } else {
                for(int i =0; i < (int)tmp->filhos.size(); i++) { 
                    if(tmp->filhos[i] != NULL) {
                        elem = buscaNo(tmp->filhos[i], valor);
                        if(elem != NULL) {
                            return elem;
                        }
                    }
                }                
            }

            return elem;
        }

        Node<T>* busca(T valor) {
            return this->buscaNo(this->raiz, valor);
        }

        void printNo(Node<T> *tmp) {
            std::cout << tmp->valor << '\n';

            for(int i =0; i < (int)tmp->filhos.size(); i++) {
                // if(tmp->filhos[i]->filhos.size() != 0) {
                //     printNo(tmp->filhos[i]);
                // }
                std::cout << tmp->filhos[i]->valor << " ";
            }

            std::cout << '\n';
        }

        void print() {
            std::cout << "\n----Árvore----\n";
            this->printNo(this->raiz);
        }
};

#endif