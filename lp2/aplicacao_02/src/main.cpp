#include <iostream>

#include "../include/arquivo.hpp"
#include "../include/analiseDocumento.hpp"

int main(int argc, char* argv[]) {
    AnaliseDocumento analise;
    std::string nomeArquivo, campo;
    char* delim;
    std::vector<std::string> campos, colunas;

    for(int i = 0; i < argc; i++) {
        std::string str = argv[i];

        if(str.compare("-d") == 0) {
            delim = argv[i+1];
        } else if(str.compare("-f") == 0) {
            // std::cout << argv[i+1] << std::endl;
            campo = argv[i+1];
        }
    }

    nomeArquivo = argv[argc-1];

    Arquivo::split(campos, campo, ',');
    for(size_t i = 0; i < campos.size(); i++) {
        Arquivo::split(colunas, campos[i], '-');
    }
    
    analise.realizarAnalise(nomeArquivo, campos, delim[0]);
    return 0;
}