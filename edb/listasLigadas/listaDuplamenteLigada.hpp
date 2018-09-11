#ifndef _LISTA_DUPLAMENTE_LIGADA_HPP_
#define _LISTA_DUPLAMENTE_LIGADA_HPP_

#include "node.hpp"

template <typename T>
class ListaDuplamenteLigada {
	private:
		Node<T> *start;
		Node<T> *end;
		int size;

	public:
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

		void push_front(T dado) {
			Node<T> *tmp = new Node<T>;
			tmp->dado = dado;

			if(this->size == 0) {
				start->next = tmp;
				tmp->previous = start;
				tmp->next = end;
				end->previous = tmp;
			} else { 
				tmp->next = start->next;
				tmp->previous = start;
				start->next = tmp;
			}

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

		void remove_front() {
			if(size == 1) {
				delete start->next;
				start->next = end;
				size -=1;
			} else if(size > 1) {
				Node<T> *next = start->next->next;
				
				delete start->next;
				next->previous = start;
				start->next = next;
				size -= 1;
			} else {
				std::cout << "Nenhum elemento a ser removido\n\n";
			}
		}

		void print() {
			if(this->size > 0) {
	            Node<T> *i = start->next;
				for(int j = 0; j < this->size; j++){
					std::cout << i->dado << " ";
					i = i->next;
				}
				std::cout << std::endl;
			} else {
                std::cout << "\nNenhum elemento na lista\n";
			}
		}


		int getSize() {
			return size;
		}
		
		T getLastElement() {
			return end->previous->dado;
		}

		T getFirstElement() {
			return start->next->dado;
		}

		bool isEmpty() {
			return size == 0;
		}
};

#endif