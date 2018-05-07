#ifndef _BOOK_
#define _BOOK_

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

class Book {
	private:
		string title;
		string author;
		int numberSheets;

	public:	
		Book();
		Book(string name, string author, int numberSheets);
		friend ostream& operator<< (ostream &o, Book const &book);
		string getTitle();
};

#endif
