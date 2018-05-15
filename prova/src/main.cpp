#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
using namespace std;

#include "../include/cd.hpp"
#include "../include/dvd.hpp"
#include "../include/livro.hpp"
#include "../include/midia.hpp"

int main() {
    vector<Empresa> empresas;
    int opcao;

    do {
        cout << "\nDigite 1 para cadastrar uma midia. ";
        cout << "\nDigite 2 para remover uma midia.";
        cout << "\nDigite 3 para editar uma midia cadastrada.";
        cout << "\nDigite 4 para listar todas as midias."
        cout << "\nDigite 5 para visualizar quantidade de cada tipo de midia cadastrada.";
        cout << "\nDigite 0 para sair.";
        cout << "\nOpcao: ";
        cin >> opcao;
        
        if(opcao == 1) {
            cout << "\nDigite 1 para cadastrar um CD. ";
            cout << "\nDigite 2 para cadastrar um DvD. ";
            cout << "\nDigite 3 para cadastrar um Livro. ";
            cout << "\nDigite 0 para sair.";
            cout << "\nOpcao: ";
            cin >> opcao;    
            if(opcao == 1) {
                Cd *cd = new Cd();
                cin >> cd;
            } else if(opcao == 1) {
                Dvd *dvd = new Dvd();
                cin >> dvd;
            } else if(opcao == 1) {
                Livro *livro = new Livro();
                cin >> Livro;
            }

            cout << "\nMidia cadastrada com sucesso!" << endl;

        } else if(opcao == 2) {
            cout << "\nDigite 1 para remover um CD. ";
            cout << "\nDigite 2 para remover um DvD. ";
            cout << "\nDigite 3 para remover um Livro. ";
            cout << "\nDigite 0 para sair.";
            cin >> opcao;

            if(opcao == 1) {
                string nomeCd;

                cin.ignore();
                cout << "\nDigite o nome do CD.";
                getline(cin, nomeCd);

            } else if(opcao == 2) {
                string titulo;
            
                cin.ignore();
                cout << "\nDigite o titulo do DvD.";
                getline(cin, titulo);

            } else if(opcao == 3) {
                string titulo;

                cin.ignore();
                cout << "\nDigite o titulo do Livro.";
                getline(cin, titulo);
            }
        } else if(opcao == 3) {
            cout << "\nDigite 1 para editar um CD. ";
            cout << "\nDigite 2 para editar um DvD. ";
            cout << "\nDigite 3 para editar um Livro. ";
            cout << "\nDigite 0 para sair.";
            cin >> opcao;

            if(opcao == 1) {
                string nomeCd;

                cin.ignore();
                cout << "\nDigite o nome do CD.";
                getline(cin, nomeCd);

            } else if(opcao == 2) {
                string titulo;
            
                cin.ignore();
                cout << "\nDigite o titulo do DvD.";
                getline(cin, titulo);

            } else if(opcao == 3) {
                string titulo;

                cin.ignore();
                cout << "\nDigite o titulo do Livro.";
                getline(cin, titulo);
            }
        } else if(opcao == 4) {
            
        }
    } while(opcao != 0);

    return 0;
}
