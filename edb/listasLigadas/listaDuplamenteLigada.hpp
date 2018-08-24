#ifndef _LISTA_DUPLAMENTE_LIGADA_HPP_
#define _LISTA_DUPLAMENTE_LIGADA_HPP_

#include "node.hpp"

template <typename T>
class ListaDuplamenteLigada {
	private:
		Node<T> *inicio;
		Node<T> *fim;
		int tamanho;

	public:
		ListaDuplamenteLigada() {  
			inicio = new Node<T>;
			fim = new Node<T>;
			inicio->proximo = fim;
			fim->anterior = inicio;
			tamanho = 0;
		}

		~ListaDuplamenteLigada() {
			Node<T> *index = inicio->proximo;
			while(index != fim) {
				index = index->proximo;
				delete index->anterior;
			}

			delete inicio;
			delete fim;
			tamanho = 0;
		}

		void push_back(T dado) {
			Node<T> *tmp = new Node<T>;
			tmp->dado = dado;

			Node<T> *anterior = fim->anterior;
			anterior->proximo = tmp;
			fim->anterior = tmp;
			tmp->proximo = fim;
			tmp->anterior = anterior;

			tamanho +=1;
		}

		void push_front(T dado) {
			Node<T> *tmp = new Node<T>;
			tmp->dado = dado;

			if(tamanho > 1) {
				inicio->proximo = tmp;
				tmp->anterior = inicio;
				tmp->proximo = fim;
				fim->anterior = tmp;
			} else { 
				tmp->proximo = inicio->proximo;
				tmp->anterior = inicio;
				inicio->proximo = tmp;
			}

			tamanho +=1;
		}

		void remove_back(){
            if(tamanho == 1){
                delete fim->anterior;
                fim->anterior = inicio;
                tamanho -= 1;
            } else if(tamanho > 1){
                Node<T> *anterior = fim->anterior->anterior;

                delete fim->anterior;
                anterior->proximo = fim;
                fim->anterior = anterior;
                tamanho -= 1;
            } else {
                std::cout << "Nenhum elemento a ser removido\n";
            }
		}

		void remove_front() {
			if(tamanho == 1) {
				delete inicio->proximo;
				inicio->proximo = fim;
				tamanho -=1;
			} else if(tamanho > 1) {
				Node<T> *proximo = inicio->proximo->proximo;
				
				delete inicio->proximo;
				proximo->anterior = inicio;
				inicio->proximo = proximo;
				tamanho -= 1;
			} else {
				std::cout << "Nenhum elemento a ser removido\n\n";
			}
		}

		void getElements(T element) {
			return inicio->proximo;
		}

		void print(int indexInicial = 0, int indexFinal = -1) {
			indexInicial = indexInicial == -1 ? tamanho-1 : indexInicial;
			indexFinal = indexFinal == -1 ? tamanho : indexFinal;
			
			std::cout << "\n-------LISTA-------\n";
			
			if(indexFinal > 0){
	            Node<T> *i = inicio->proximo;
				for(int j = 0; j < indexFinal; j++){
					if(j >= indexInicial) {
						std::cout << i->dado << " ";
					}
					i = i->proximo;
				}
				std::cout << std::endl;
			} else {
                std::cout << "Nenhum elemento na lista\n";
			}

			std::cout << std::endl;
		}
};

#endif