#include <iostream>

#include "../include/arquivo.hpp"
#include "../include/analiseDocumento.hpp"

int main(int argc, char* argv[]) {
    AnaliseDocumento analise;
    
    for(int i = 0; i < argc; i++) {
        std::string str = argv[i];

        if(str.compare("--std")) {
            analise.realizarAnalise("entrada.in");
            break;
        } else if(str.compare("--file")) {
            analise.realizarAnalise(argv[i+1]);
            break;
        }
    }

    return 0;
}