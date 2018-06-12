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
        string anoLancamento;  
        std::vector<Midia> midias;

    public:
        Midia();
        ~Midia();
        friend ostream& operator<< (ostream &o, Midia &midia);
        friend void operator>> (istream &i, Midia &midia);
        void cadastrarMidia(Midia midia);
        void removerMidia(string titulo);
        void listarTodasMidias();
        void listarQtdMidiasPorTipo();
};

#endif