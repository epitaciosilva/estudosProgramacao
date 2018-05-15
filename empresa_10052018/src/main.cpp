#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

#include "../include/empresa.hpp"
#include "../include/gerente.hpp"
#include "../include/operario.hpp"
#include "../include/secretaria.hpp"

int main() {
    vector<Empresa> empresas;
    int opcao;

    do {
        cout << "Digite 1 para cadastrar uma empresa. ";
        cout << "Digite 2 para cadastrar um funcionario a uma empresa.";
        cout << "Digite 3 para listar todos os funcionarios de uma empresa.";
        cout << "Digite 4 para dar um aumento a todos os funcionarios.";
        cout << "Digite 0 para sair.";
        cout << "Opcao: ";
        cin >> opcao;
        
        if(opcao == 1) {
            cin >> empresas;
        } else if(opcao == 1) {
            string nomeEmpresa;
            int opcaoDois;
        
            cout << "Digite o nome da empresa do funcionário: ";
            cin >> nomeEmpresa;

            cout << "Digite 1 para cadastrar um GERENTE. ";
            cout << "Digite 2 para cadastrar uma SECRETARIA. ";
            cout << "Digite 3 para cadastrar um OPERARIO. ";
            cin >> opcaoDois;

            if(opcaoDois == 1) {
                Funcionario *gerente = new Gerente();

                int indexEmpresa = Empresa::encontrarEmpresa(empresas, nomeEmpresa);
                
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
            cout << empresas[0].getFuncionarios();
        } else if(opcao == 4) {
            
        }
    } while(opcao != 0);

    return 0;
}
