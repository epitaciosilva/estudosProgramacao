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
			pilha->push_back(dado);
		}

		void desempilhar() {
			pilha->remove_back();
		}

		void imprimir() {
			pilha->print();
		}

		void imprimirMenorElemento() {
			menorElemento->print(-1);
		}
};
#endif