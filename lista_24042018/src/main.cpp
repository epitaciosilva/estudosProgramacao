#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../include/list.hpp"
#include "../include/book.hpp"

int main() {
	List<Book> listBooks;
	List<double> listDouble;
	List<int> listInt;
	
	int option = 0;

	do {
		cout << "\nEnter 1 to add element into a list\n";
		cout << "Enter 2 to remove element from a list\n";
		cout << "Enter 3 to show all elements from a list\n";
		cout << "Enter 4 to search element from a list\n";
		cout << "Enter 0 to get out\n";
		cout << "Option: ";
		cin >> option;

		if(option == 1 || option == 2) {
			int optionElement = 0;

			cout << "\nEnter 1 for a book\n";
			cout << "Enter 2 for a double\n";
			cout << "Enter 3 for a int\n";
			cout << "Option: ";
			cin >> optionElement;

			if(option == 1 && optionElement == 1) {
				string title;
				string author;
				int numberPages;

				cin.ignore();
				cout << "\nEnter the title: ";
				getline(cin, title);
				cout << "Enter the author: ";
				getline(cin, author);
				cout << "Enter the number of pages: ";
				cin >> numberPages;

				Book book(title, author, numberPages);
				listBooks.add(book);

			} else if(option == 1 && optionElement == 2) {
				double value;
				
				cout << "\nEnter value double: ";
				cin >> value;

				listDouble.add(value);

			} else if(option == 1 && optionElement == 3) {
				int value;
				
				cout << "\nEnter value int: ";
				cin >> value;

				listInt.add(value);

			} else if(option == 2 && optionElement == 1) {
				string title;

				cin.ignore();
				cout << "\nEnter the title of the book: "; 
				getline(cin, title);

				Book book;
				book.setTitle(title);
				
				listBooks.remove(book);
			} else if(option == 2 && optionElement == 2) {
				double value;

				cout << "\nEnter the value double: "; 
				cin >> value;
				
				listDouble.remove(value);
			} else if(option == 2 && optionElement == 3) {
				int value;

				cout << "\nEnter the value int: "; 
				cin >> value;
				
				listInt.remove(value);
			}
		} else if(option == 3) {
			int optionList = 0;

			cout << "\nEnter 1 for a list of book\n";
			cout << "Enter 2 for a list of double\n";
			cout << "Enter 3 for a list of int\n";
			cout << "Option: ";
			cin >> optionList;
			
			switch(optionList) {
				case 1:
					listBooks.showAll();
					break;
				case 2:
					listDouble.showAll();
					break; 
				case 3:
					listInt.showAll();
					break;
				default:
					break;
			}
		} else if(option == 4) {
			int optionElement = 0;

			cout << "\nEnter 1 for a book\n";
			cout << "Enter 2 for a double\n";
			cout << "Enter 3 for a int\n";
			cout << "Option: ";
			cin >> optionElement;
			
			if(optionElement == 1) {
				string title;
				cout << "\nEnter the title: ";

				cin.ignore();
				getline(cin, title);

				Book book;
				book.setTitle(title);

				listBooks.showSigle(book);
			} else if(optionElement == 2) { 
				double value;

				cout << "\nEnter the value double: ";
				cin >> value;

				listDouble.showSigle(value);
			} else if(optionElement == 3) { 
				int value;

				cout << "\nEnter the value int: ";
				cin >> value;

				listInt.showSigle(value);
			}
		}
	} while(option != 0);

	return 0;
}
