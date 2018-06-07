#include <iostream>
#include <string>

#include "../include/sapo.hpp"
#include "../include/pista.hpp"
#include "../include/corrida.hpp"
#include "../include/lerArquivo.hpp"

int main() {
    LerArquivo arquivo;
    Corrida corrida;
 
    arquivo.lerArquivo("./arquivo.txt");
    corrida.inserirSaposPistas(arquivo.getLinhas());
    corrida.iniciarCorrida();
    return 0;
}