#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

#include "../include/book.hpp"

Book::Book() { }

Book::~Book() { }

Book::Book(string title, string author, int numberPages) { 
	this->title = title;
	this->author = author;
	this->numberPages = numberPages;
}

ostream& operator<< (ostream &o, Book const &book) {
	
	o << "Title: " << book.title << endl;
	o << "Author: " << book.author << endl;
	o << "Number of pages: " << book.numberPages << endl;		
	
	return o;
}

string Book::getTitle() {
	return this->title;
}

void Book::setTitle(string title) {
	this->title = title;
}
