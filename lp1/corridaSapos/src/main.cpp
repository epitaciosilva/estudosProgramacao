/**
* @author Epitácio Bessa
* @file main.cpp
* @sa https://github.com/epitaciosilva/cppClass/blob/corridaSapos/lp1/corridaSapos/src/main.cpp
* @since 29/05/18
* @date 07/06/18
* @brief Implementações da classe principal ou main
*/


#include <iostream>
#include <string>

#include "../include/sapo.hpp"
#include "../include/pista.hpp"
#include "../include/corrida.hpp"
#include "../include/lerArquivo.hpp"

int main() {
    std::string arquivoSapo = "./sapos.txt";
    std::string arquivoPistas = "./pistas.txt";
    Corrida corrida;

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
            corrida.imprimirEstatisticasPistas();
            std::string nomePista;

            std::cout << "\nInsira nome da pista que acontecerá a corrida: \n";
            std::cin >> nomePista;
            
            corrida.iniciarCorrida(nomePista);
        } else if(opcao == 4) {
            std::string descricao;
            std::string identificador;

            std::cout << "\nDigite o nome do sapo: \n";
            std::cin >> descricao;
            std::cout << "\nDigite o identificador do sapo: \n";
            std::cin >> identificador;
            
            Sapo sapo(descricao, identificador);
            corrida.escreverSapo(sapo, arquivoSapo);
        } else if(opcao == 5) {
            std::string descricao;
            int distancia;

            std::cout << "\nDigite o nome da pista: \n";
            std::cin >> descricao;
            std::cout << "\nDigite o tamanho da pista: \n";
            std::cin >> distancia;
            
            Pista pista(descricao, distancia);
            corrida.escreverPista(pista, arquivoPistas);
        }
    }
    return 0;
}