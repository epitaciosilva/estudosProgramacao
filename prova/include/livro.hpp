#ifndef _LIVRO_HPP_
#define _LIVRO_HPP_

#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "midia.hpp"

class Livro : public Midia {
    private: 
        string editora;
        string isbn;

    public:
        Livro();
        Livro::Livro(string titulo, string autor, int anoLancamento, string editora, string isbn);
        ~Livro();
        Livro cadastrar();

};

#endif