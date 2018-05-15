#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
using namespace std;

#include "../include/empresa.hpp"
#include "../include/gerente.hpp"
#include "../include/operario.hpp"
#include "../include/secretaria.hpp"

int main() {
    vector<Empresa> empresas;
    int opcao;

    do {
        cout << "\nDigite 1 para cadastrar uma empresa. ";
        cout << "\nDigite 2 para cadastrar um funcionario a uma empresa.";
        cout << "\nDigite 3 para listar todos os funcionarios de uma empresa.";
        cout << "\nDigite 4 para dar um aumento a todos os funcionarios.";
        cout << "\nDigite 0 para sair.";
        cout << "\nOpcao: ";
        cin >> opcao;
        
        if(opcao == 1) {
            cin >> empresas;
        } else if(opcao == 2) {
            string nomeEmpresa;
            int opcaoDois;
            
            cout << "\nDigite o nome da empresa do funcionário: ";
            getline(cin, nomeEmpresa);

            cout << "\nDigite 1 para cadastrar um GERENTE. ";
            cout << "\nDigite 2 para cadastrar uma SECRETARIA. ";
            cout << "\nDigite 3 para cadastrar um OPERARIO. ";
            cin >> opcaoDois;

            if(opcaoDois == 1) {

                int indexEmpresa = Empresa::encontrarEmpresa(empresas, nomeEmpresa);
                Funcionario *gerente = new Gerente();
                
                if(indexEmpresa != -1) {
                    empresas[indexEmpresa].cadastrarProfissional(*gerente);
                } else {
                    cout << "Empresa não encontrada";
                }

                delete gerente;

            } else if(opcaoDois == 1) {
                Funcionario *secretaria = new Secretaria();

                int indexEmpresa = Empresa::encontrarEmpresa(empresas, nomeEmpresa);
                
                if(indexEmpresa != -1) {
                    empresas[indexEmpresa].cadastrarProfissional(*secretaria);
                } else {
                    cout << "Empresa não encontrada";
                }

                delete secretaria;

            } else if(opcaoDois == 1) {
                Funcionario *operario = new Operario();

                int indexEmpresa = Empresa::encontrarEmpresa(empresas, nomeEmpresa);

                if(indexEmpresa != -1) {
                    empresas[indexEmpresa].cadastrarProfissional(*operario);
                } else {
                    cout << "Empresa não encontrada";
                }

                delete operario;
            }
        } else if(opcao == 3) {
            string nomeEmpresa;

            cout << "Digite o nome da empresa do funcionário: ";
            cin >> nomeEmpresa;

            int indexEmpresa = Empresa::encontrarEmpresa(empresas, nomeEmpresa);
            cout << empresas[indexEmpresa].getFuncionarios();
        } else if(opcao == 4) {
            
        }
    } while(opcao != 0);

    return 0;
}
