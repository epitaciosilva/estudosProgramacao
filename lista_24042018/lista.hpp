#ifndef _LISTA_H_
#define _LISTA_H_

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "book.hpp"

template<class Type>
class Lista {
	private:
		vector<Type> lista; 

	public:	
		Lista();
		void addValue(Type value);
		void sort();
		void showAll();
		void showSigle(Type value);
		size_t search(Type value);
		void exclude(Type value);
};

template<class Type>
Lista<Type>::Lista() {}

template<class Type>
void Lista<Type>::addValue(Type value) {
	this->lista.push_back(value);
}

template<class Type>
void Lista<Type>::sort() {
	for(size_t i = 0; i < this->lista.size(); i++) {
		for(size_t j = 0; j < this->lista.size(); j++) {
			if( i!=j  && this->lista[i] < this->lista[j]) {
				Type guardar = this->lista[i];
				this->lista[i] = this->lista[j];
				this->lista[j] = guardar;
			}
		}	
	}
}

template<>
void Lista<Book>::sort() {
	
sort(this->lista.begin(), this->lista.end(), sortString);
//	for(size_t i = 0; i < this->lista.size(); i++) {
//		for(size_t j = 0; j < this->lista.size(); j++) {
//			if( i!=j  && this->lista[i] < this->lista[j]) {
//				Type guardar = this->lista[i];
//				this->lista[i] = this->lista[j];
//				this->lista[j] = guardar;
//			}
//		}	
//	}
}

template<class Type>
void Lista<Type>::showAll() {
	cout << "\n----- Show all -----" << endl;
	for(size_t i = 0; i < this->lista.size(); i++) {
		cout << this->lista[i] << endl;	
	}
}

template<class Type>
void Lista<Type>::showSigle(Type value) {
	size_t indexShow = this->search(value);
	if(indexShow != -1) {
		cout << "\n----- Show sigle -----" << endl;
		cout << this->lista[indexShow] << endl;	
	}
}

template<class Type>
size_t Lista<Type>::search(Type value) {
	for(size_t index = 0; index < this->lista.size(); index++) {
		if(this->lista[index] == value) {
			return index;		
		}
	}

	cout << "\nValue does not exist" << endl;
	return -1;
}

template<class Type>
void Lista<Type>::exclude(Type value) {
	size_t indexExclude = this->search(value);
	if(indexExclude != -1) {
		this->lista.erase(lista.begin()+indexExclude);
	}
}

#endif
