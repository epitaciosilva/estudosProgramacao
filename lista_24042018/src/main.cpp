#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../include/lista.hpp"
#include "../include/book.hpp"

int main() {
	Book book("o hobbit", "J. R. R. Tolkien", 200);
	Lista<Book> lista;
	lista.addValue(book);

	Book book1("a livro", "Tolkien", 200);
	lista.addValue(book1);
	
	lista.showAll();
	return 0;
}
