#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

#include "book.hpp"

Book::Book(){}

Book::Book(string title, string author, int numberSheets) { 
	this->title = title;
	this->author = author;
	this->numberSheets = numberSheets;
}

ostream& operator<< (ostream &o, Book const &book) {
	o << "\nTitle: " << book.title << endl;
	o << "Author: " << book.author << endl;
	o << "Number of sheets: " << book.numberSheets << endl;		
	
	return o;
}


