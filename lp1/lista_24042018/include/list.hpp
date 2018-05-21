#ifndef _LISTA_H_
#define _LISTA_H_

#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#include "./book.hpp"

template<class Type>
class List {
	private:
		vector<Type> list; 
		void sort();
		static bool compString(Book b1, Book b2);

	public:	
		List();
		void add(Type value);
		void showAll();
		void showSigle(Type value);
		size_t search(Type value);
		void remove(Type value);
};

template<class Type>
bool List<Type>::compString(Book b1, Book b2) {
	return std::strcmp(b1.getTitle().c_str(), b2.getTitle().c_str()) < 0;
}

template<class Type>
List<Type>::List() {}

template<class Type>
void List<Type>::add(Type value) {
	this->list.push_back(value);
	this->sort();
}

template<class Type>
void List<Type>::sort() {
	for(size_t i = 0; i < this->list.size(); i++) {
		for(size_t j = 0; j < this->list.size(); j++) {
			if( i!=j  && this->list[i] < this->list[j]) {
				Type guardar = this->list[i];
				this->list[i] = this->list[j];
				this->list[j] = guardar;
			}
		}	
	}
}

template<>
void List<Book>::sort() {
	std::sort(this->list.begin(), this->list.end(), this->compString);
}


template<class Type>
void List<Type>::showAll() {
	cout << "\n----- All Elements -----" << endl;
	for(size_t i = 0; i < this->list.size(); i++) {
		cout << this->list[i] << endl;	
	}
}

template<class Type>
size_t List<Type>::search(Type value) {
	for(size_t index = 0; index < this->list.size(); index++) {
		if(this->list[index] == value) {
			return index;		
		}
	}

	cout << "\nValue does not exist!" << endl;
	return -1;
}

template<>
size_t List<Book>::search(Book book) {
	for(size_t index = 0; index < this->list.size(); index++) {
		if(this->list[index].getTitle() == book.getTitle()) {
			return index;		
		}
	}

	cout << "\nValue does not exist!" << endl;
	return -1;
}

template<class Type>
void List<Type>::remove(Type value) {
	size_t indexExclude = this->search(value);

	if(indexExclude != (size_t) -1) {
		this->list.erase(list.begin()+indexExclude);
		cout << "Value deleted with success\n";
	}
}

template<>
void List<Book>::remove(Book book) {
	size_t indexExclude = this->search(book);
	
	if(indexExclude != (size_t) -1) {
		this->list.erase(list.begin()+indexExclude);
		cout << "\nBook deleted with success\n";
	}
}


template<class Type>
void List<Type>::showSigle(Type value) {
	size_t indexShow = this->search(value);

	if(indexShow != (size_t) -1) {
		cout << "\n----- Value -----" << endl;
		cout << this->list[indexShow] << endl;	
	}
}

template<>
void List<Book>::showSigle(Book book) {
	size_t indexShow = this->search(book);

	if(indexShow != (size_t) -1) {
		cout << "\n----- Book -----" << endl;
		cout << this->list[indexShow] << endl;	
	}
}

#endif
