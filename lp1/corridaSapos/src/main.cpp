#include <iostream>
#include <string>

#include "../include/sapo.hpp"
#include "../include/pista.hpp"
#include "../include/corrida.hpp"
#include "../include/lerArquivo.hpp"

int main() {
    std::string arquivoSapo;
    std::string arquivoPistas;
    Corrida corrida;

    std::cout << "Insira o local do arquivo dos sapos: \n";
    std::cin >> arquivoSapo;

    std::cout << "Insira o local do arquivo das pistas: \n";
    std::cin >> arquivoPistas;

    corrida.inserirSapos(arquivoSapo);
    corrida.inserirPistas(arquivoPistas);

    int opcao = -1;

    while(opcao != 0) {
        std::cout << "\nDigite 1 para ver estatisticas dos sapos" << std::endl
                    << "Digite 2 para ver estatisticas das pistas" << std::endl
                    << "Digite 3 para iniciar uma corrida" << std::endl
                    << "Digite 4 para criar os sapos" << std::endl
                    << "Digite 5 para criar a pista" << std::endl
                    << "Digite 0 para sair" << std::endl;
        std::cin >> opcao;

        if(opcao == 1) {
            corrida.imprimirEstatisticasSapos();
        } else if(opcao == 2) {
            corrida.imprimirEstatisticasPistas();
        } else if(opcao == 3) {
            corrida.iniciarCorrida();
        } else if(opcao == 4) {

        } else if(opcao == 5) {

        }
    }
    return 0;
}