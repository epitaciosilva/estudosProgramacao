#ifndef _ARVORE_GERAL_HPP_
#define _ARVORE_GERAL_HPP_

#include <vector>
#include "./node.hpp"

template <typename T>
class Arvore {
    private:
        Node<T> *raiz;
        bool status;

	public:
		Arvore() { 
            this->raiz = NULL;
        }
        
		~Arvore() { }

        void addIrmao(Node<T> *tmp, Node<T> *root) {
            Node<T> *iter = root;
            while(iter->irmao != NULL) {
                if(iter->dado == tmp->dado) {
                    iter = iter->irmao;
                } else {
                    // até o momento o 'irmao' não possui filho,
                    // mas caso contrário, esse deve ser o caminho
                    addFilho(tmp, root);
                    return;
                }
            }
            iter->irmao = tmp;
        }

        void addFilho(Node<T> *tmp, Node<T> *root) {
            Node<T> *iter = root;
            while(iter->filho != NULL) {
                // tem que começar dessa maneira, senão pega o valor da raiz.
                if(iter->filho->dado != tmp->dado) {
                    iter = iter->filho;
                } else {
                    // manda adicionar como irmão se for igual
                    addIrmao(tmp, iter->filho);
                    return;
                }
            }
            iter->filho = tmp;
        }

        void adicionar(T valor) {
            Node<T> *tmp = new Node<T>;
            tmp->dado = valor;
            tmp->filho = NULL;
            tmp->irmao = NULL;

            if(this->raiz == NULL) {
                this->raiz = new Node<T>;
            }
            
            this->addFilho(tmp, this->raiz);
        }

        void print() {
            std::cout << "---------\"Árvore\"--------\n";
            Node<T> *filho = this->raiz;
            while(filho->filho != NULL) {
                // 'sempre' começa pelo filho, pois não se mexe na raiz.
                filho = filho->filho;
                std::cout << filho->dado << " ";

                // enquanto o filho em questão tiver um irmao (for igual a ele),
                // continue a imprimi-los
                if(filho->irmao != NULL) {
                    // pega o node mesmo, não o endereço, senão quebra a interação com dos filhos.
                    Node<T> irmao = *filho;
                    while(irmao.irmao != NULL) {
                        irmao = *irmao.irmao;
                        std::cout << irmao.dado << " ";
                    }
                } 

                std::cout << "\n";
            }
        }
};

#endif