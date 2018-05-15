#ifndef _MIDIA_HPP_
#define _MIDIA_HPP_

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Midia {
    protected: 
    	string titulo;
    	string autor;
        int anoLancamento;  
        std::vector<Midia> midias;

    public:
        Midia();
        ~Midia();
        void cadastrarCd();
        void cadastrarDvD();
        void cadastrarLivro();
};

#endif