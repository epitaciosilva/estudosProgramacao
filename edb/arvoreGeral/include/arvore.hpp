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
                // analogamente ao do addFilho  
                if(tmp->valor >= iter->irmao->valor) {
                    iter = iter->irmao;
                } else {
                    addFilho(tmp, iter->irmao);
                    return;
                }
            }

            tmp->pai = iter;
            iter->irmao = tmp;
        }

        void addFilho(Node<T> *tmp, Node<T> *root) {
            Node<T> *iter = root;
            while(iter->filho != NULL) {
                // 'iter->filho->valor' => tem que começar dessa maneira, senão pega o valor da raiz.
                // os valores menores ao inicial ficam a esquerda (filho) e os maiores a direita (irmao)
                if(tmp->valor < iter->filho->valor) {
                    iter = iter->filho;
                } else if(tmp->valor > iter->filho->valor) {
                    addIrmao(tmp, iter->filho);
                    return;
                }
            }
            
            tmp->pai = iter;
            iter->filho = tmp;
        }

        void adicionar(T valor) {
            Node<T> *tmp = new Node<T>(valor);

            if(this->raiz == NULL) {
                this->raiz = tmp;
                return;
            }

            this->addFilho(tmp, this->raiz);
        }

        bool buscarFilho(Node<T> *filho, T value, bool remover) {
            if(filho == NULL) {
                return false;
            } else if(filho->valor == value && remover) {
                this->remover(filho);
            } else if(filho->valor == value || buscarIrmao(filho->irmao, value, remover)) {
                return true;
            }

            return buscarFilho(filho->filho, value, remover);
        }

        bool buscarIrmao(Node<T> *irmao, T value, bool remover) {
            if(irmao == NULL) {
                return false;
            } else if(irmao->valor == value && remover) {
                this->remover(irmao);
            } else if(irmao->valor == value || buscarFilho(irmao->filho, value, remover)) {
                return true;
            }
            
            return buscarIrmao(irmao->irmao, value, remover);
        }

        bool buscar(T value, bool remover = false) {
            return this->buscarFilho(this->raiz, value, remover);
        }

        void remover(T value) {
            this->buscar(value, true);
        }

        void remover(Node<T> *no) {
            if(no->pai != NULL) {
                no->pai->filho = NULL;
                no->pai->irmao = NULL;
            }
        }

        void print() {
            std::cout << "---------\"Árvore\"--------\n";
            printFilho(this->raiz);
            std::cout << '\n';
        }

        void printFilho(Node<T> *no, std::string espaco = "") {
            if(no != NULL && no->valor < 10 && no->valor >= 0) {
                std::cout << espaco << "0" << no->valor;
            } else if(no != NULL) {
                std::cout << espaco << no->valor;
            }

            if(no->irmao != NULL) {
                this->printIrmao(no->irmao, "   ");
            }

            if(no->filho != NULL) {
                std::cout << '\n';
                this->printFilho(no->filho, espaco);
            }

            return;
        }

        void printIrmao(Node<T> *no, std::string espaco = "") {
            if(no != NULL && no->valor < 10 && no->valor >= 0) {
                std::cout << " 0" << no->valor;
            } else if(no != NULL) {
                std::cout << " " << no->valor;
            }

            if(no->irmao != NULL) {
                this->printIrmao(no->irmao, espaco+espaco);
            }

            if(no->filho != NULL) {
                std::cout << '\n';
                this->printFilho(no->filho, espaco);
            }

            return;
        }

};

#endif