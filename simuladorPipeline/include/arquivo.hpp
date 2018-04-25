#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Arquivo {
    private:

    public:
        Arquivo();
        static vector<string> lerArquivo(string nomeArquivo);
        static vector<string> split(string instrucao, char c1 = ' ', char c2 = ',', char c3 = '\n');
};
#endif