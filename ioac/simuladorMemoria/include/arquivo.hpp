#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Arquivo {
    private:

    public:
        Arquivo();
        static std::vector<std::string> lerArquivo(std::string nomeArquivo);
};
#endif