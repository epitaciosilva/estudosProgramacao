#ifndef _DVD_HPP_
#define _DVD_HPP_

#include <string>
#include <iostream>
using namespace std;

#include "midia.hpp"

class Dvd : public Midia {
    protected:
        string duracao;
        string classificacao;        

    public:
        Dvd();
        Dvd(string titulo, string autor, string anoLancamento, string duracao, string classficacao);
        ~Dvd();
        friend void operator>> (istream &i, Dvd &dvd);
};

#endif