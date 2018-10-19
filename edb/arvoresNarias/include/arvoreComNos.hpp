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

        void addElemento(T valor) {
            if(this->raiz == NULL) {
                this->raiz = new Node<T>;
                this->raiz->valor = valor;
            } else {
                if((int)this->raiz->filhos.size() <= this->N) {
                    this->raiz->addFilho(valor);
                } else {
                    std::cout << "Nó cheio.\n";
                }
            }
        }

        void print() {
            std::cout << "\n----Árvore----\n";
            std::cout << this->raiz->valor << '\n';

            for(int i =0; i < (int)this->raiz->filhos.size(); i++) {
                std::cout << this->raiz->filhos[i].valor << " ";
            }

            std::cout << '\n';
        }
};

#endif