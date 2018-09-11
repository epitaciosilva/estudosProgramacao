#ifndef _PILHA_
#define _PILHA_

#include <iostream>
#include "../../../../listasLigadas/listaDuplamenteLigada.hpp"

template<typename T>
class Pilha {
	private:
		ListaDuplamenteLigada<T> *pilha;
		ListaDuplamenteLigada<T> *menorElemento;

	public: 
		Pilha() { 
			pilha = new ListaDuplamenteLigada<T>;
			menorElemento = new ListaDuplamenteLigada<T>;
		}

		~Pilha() {
			delete pilha;
		}

		void empilhar(T dado) {
			if(pilha->isEmpty()) {
			// std::cout << pilha->isEmpty() << " vazio\n\n";
				menorElemento->push_back(dado);
			} else if(dado <= menorElemento->getLastElement()) {
				menorElemento->push_back(dado);
			}

			pilha->push_front(dado);
		}

		void desempilhar() {
			if(pilha->getLastElement() == menorElemento->getLastElement()) {
				menorElemento->remove_back();
			}
			pilha->remove_back();
		}

		void imprimir() {
			pilha->print();
		}

		void imprimirMenorElemento() {
			std::cout << "\nMenor elemento: " << menorElemento->getLastElement() << std::endl;
		}
};
#endif