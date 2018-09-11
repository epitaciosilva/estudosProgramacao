#ifndef _CONJUNTO_DE_PILHA_HPP_
#define _CONJUNTO_DE_PILHA_HPP_

#include <vector>
#include "../../../../listasLigadas/listaDuplamenteLigada.hpp"

template<typename T>
class ConjuntoDePilhas {
	private:
		std::vector<ListaDuplamenteLigada<T>> pilhas;

	public: 
		ConjuntoDePilhas() { 
			pilhas.push_back(*(new ListaDuplamenteLigada<T>));
		}

		~ConjuntoDePilhas() {
		}

		void empilhar(T dado) {
			if(pilhas.back().getSize() == 3) {
				ListaDuplamenteLigada<T> nova;
				pilhas.push_back(nova);
			} else {
				pilhas.back().push_front(dado);
			}
		}

		void desempilhar() {
			if(pilhas.back().getSize() == 0) {
				pilhas.pop_back();
			}
			pilhas.back().remove_back();
		}

		void imprimir() {
			std::cout << "\n-----Pilha------\n";
			for(size_t i = 0; i < pilhas.size(); i++) {
				pilhas[i].print();
			}
		}
};
#endif