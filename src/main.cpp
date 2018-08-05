#include <iostream>


#include "../include/lerArquivo.hpp"
#include "../include/analiseDocumento.hpp"

int main(int argc, char* argv[]) {
    AnaliseDocumento analise;

    for(int i = 1; i < argc; i++) {
        std::string str = argv[i];

        if(str.compare("--std")) {
            analise.realizarAnalise("entrada.in");
        } else if(str.compare("--file")) {
            analise.realizarAnalise(argv[i+1]);
        }
    }

    return 0;
}