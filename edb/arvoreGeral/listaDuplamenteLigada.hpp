#ifndef _LISTA_DUPLAMENTE_LIGADA_HPP_
#define _LISTA_DUPLAMENTE_LIGADA_HPP_

#include "node.hpp"

template <typename T>
class ListaDuplamenteLigada {
	public:
		Node<T> *start;
		Node<T> *end;
		int size;

		ListaDuplamenteLigada() {  
			start = new Node<T>;
			end = new Node<T>;
			start->next = end;
			end->previous = start;
			size = 0;
		}

		~ListaDuplamenteLigada() {
			Node<T> *index = start->next;
			while(index != end) {
				index = index->next;
				delete index->previous;
			}

			delete start;
			delete end;
			size = 0;
		}

		void push_back(T dado) {
			Node<T> *tmp = new Node<T>;
			tmp->dado = dado;	

			Node<T> *previous = end->previous;
			previous->next = tmp;
			end->previous = tmp;
			tmp->next = end;
			tmp->previous = previous;

			size +=1;
		}

		void remove_back(){
            if(size == 1){
                delete end->previous;
                end->previous = start;
                size -= 1;
            } else if(size > 1){
                Node<T> *previous = end->previous->previous;

                delete end->previous;
                previous->next = end;
                end->previous = previous;
                size -= 1;
            } else {
                std::cout << "Nenhum elemento a ser removido\n";
            }
		}

		void print() {
			if(this->size > 0) {
	            Node<T> *iter = this->start->next;
				for(int j = 0; j < this->size; j++){
					std::cout << iter->dado << " ";
					iter = iter->next;
				}
				std::cout << std::endl;
			} else {
                std::cout << "\nNenhum elemento na lista\n";
			}
		}

		static void merge(ListaDuplamenteLigada<T> *lista1, ListaDuplamenteLigada<T> *lista2) {
			lista1->end->previous->next = lista2->start->next;
			lista2->start->next->previous = lista1->end->previous;
			lista1->end = lista2->end;
			lista1->size += lista2->size;
		}
};

#endif