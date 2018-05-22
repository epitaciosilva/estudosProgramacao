#ifndef _CD_HPP_
#define _CD_HPP_

#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "midia.hpp"

class Cd : public Midia {
    protected: 
        int qtdFaixas;
        string gravadora;

    public:
        Cd();
        Cd(string titulo, string autor, string anoLancamento, int qtdFaixas, string gravadora);
        ~Cd();
        friend void operator>> (istream &i, Cd *cd);
        friend ostream& operator<< (ostream &o, Cd &midia);
};


#endif