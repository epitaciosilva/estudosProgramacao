#ifndef _LISTA_H_
#define _LISTA_H_

#include <string>
#include <vector>
using namespace std;

template<class Type>
class Lista {
	private:
		vector<Type> lista; 

	public:	
		Lista();
		void addValue(Type value);
		void sort();
		void show();
		// int buscar(Type Type);
		// void remover(Type *Type);
		// void listar(vector<Type> lista);
};	

template<class Type>
Lista<Type>::Lista() {}

template<class Type>
void Lista<Type>::addValue(Type value) {
	this->lista.push_back(value);
	sort();
}

template<class Type>
void Lista<Type>::sort() {
	for(int i = 0; i < this->lista.size(); i++) {
		for(int j = 0; j < this->lista.size(); j++) {
			if( i!=j  && this->lista[i] < this->lista[j]) {
				Type guardar = this->lista[i];
				this->lista[i] = this->lista[j];
				this->lista[j] = guardar;
			}
		}	
	}
}

template<class Type>
void Lista<Type>::show() {
	for(int i = 0; i < this->lista.size(); i++) {
		cout << this->lista[i] << endl;	
	}
}



#endif