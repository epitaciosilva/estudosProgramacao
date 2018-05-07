#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../include/lista.hpp"
#include "../include/book.hpp"

int main() {
	Book book("O Hobbit", "J. R. R. Tolkien", 200);
	Lista<Book> lista;
	lista.addValue(book);

	return 0;
}
