#include <iostream>
#include <string>
using namespace std;

#include "../include/produto.hpp"
#include "../include/produtoDuravel.hpp"
#include "../include/produtoNaoDuravel.hpp"
#include "../include/deposito.hpp"
#include "../include/carro.hpp"
#include "../include/livro.hpp"
#include "../include/celular.hpp"
#include "../include/pizza.hpp"
#include "../include/chocolate.hpp"
#include "../include/refrigerante.hpp"

int main() {
    int opcao = -1;
    Deposito deposito;
    string menuPrincipal = "\n------ MENU -------"
        "\nDigite 1 para adicionar um produto"
        "\nDigite 2 para remover um produto"
        "\nDigite 3 para saber o produto com maior valor"
        "\nDigite 4 para saber a quantidade de produtos no deposito"
        "\nDigite 5 para saber se o deposito está vázio"
        "\nDigite 0 para sair\n";

    string menuAdicionar = "\n------ MENU -------"
        "\nDigite 1 para adicionar um carro"
        "\nDigite 2 para adicionar um livro"
        "\nDigite 3 para adidionar um celular"
        "\nDigite 4 para adicionar um chocolate" 
        "\nDigite 5 para adicionar uma pizza"
        "\nDigite 6 para adicionar um refrigerante"
        "\nDigite 0 para sair\n";

    while(opcao != 0) {
        cout << menuPrincipal;
        cin >> opcao;

        if(opcao == 1) {
            cout << menuAdicionar;
            cin >> opcao;
            if(opcao >= 1 && opcao <= 6) {
                string nome;
                double preco;
                string marca;
                string descricao;
                string dataFabricacao;

                cout << "Insira o nome do produto: ";
                cin >> nome;
                cout << "Insira o preco do produto: ";
                cin >> preco;
                cout << "Insira a marca do produto: ";
                cin >> marca;
                cout << "Insira a descricao do produto: ";
                cin >> descricao;
                cout << "Insira a data de fabricacao do produto: ";
                cin >> dataFabricacao;

                if(opcao >= 1 && opcao <=3) {
                    string materialPredominante;
                    int durabilidade;
                    
                    cout << "Insira o material predominante: ";
                    cin >> materialPredominante;
                    cout << "Insira a durabilidade em dias: ";
                    cin >> durabilidade;
                    
                    if(opcao == 1) {
                        int qtdPortas;
                        string cor;
                        
                        cout << "Insira a quantidade de portas: ";
                        cin >> qtdPortas;
                        cout << "Insira a cor: ";
                        cin >> cor;   
                        
                        Produto* produto = new Carro(nome, preco, marca, descricao, 
                            dataFabricacao, materialPredominante, durabilidade, qtdPortas, cor
                        );
                        
                        deposito.adicionarProduto(*produto);

                    } else if(opcao == 2) {
                        int qtdPaginas;
                        
                        cout << "Insira a quantidade de págians: ";
                        cin >> qtdPaginas;

                        Produto* produto = new Livro(nome, preco, marca, descricao, 
                            dataFabricacao, materialPredominante, durabilidade, qtdPaginas
                        );
                        
                        deposito.adicionarProduto(*produto);

                    } else  {
                        Produto* produto = new Celular(nome, preco, marca, descricao, 
                            dataFabricacao, materialPredominante, durabilidade
                        );

                        deposito.adicionarProduto(*produto);
                    }
                } else if(opcao >= 4 && opcao <= 6) {
                    string dataValidade;
                    string genero;

                    cout << "Insira a data de validade: ";
                    cin >> dataValidade;
                    cout << "Insira o genero :";
                    cin >> genero;

                    if(opcao == 4) {
                        Produto* produto = new Chocolate(nome, preco, marca, descricao,
                            dataFabricacao, dataValidade, genero
                        );
                        
                        deposito.adicionarProduto(*produto);

                    } else if(opcao == 5) {
                        Produto* produto = new Pizza(nome, preco, marca, descricao,
                            dataFabricacao, dataValidade, genero
                        );

                        deposito.adicionarProduto(*produto);
                    } else {
                        Produto* produto = new Refrigerante(nome, preco, marca, descricao,
                            dataFabricacao, dataValidade, genero
                        );

                        deposito.adicionarProduto(*produto);
                    }
                }
            }
        } else if(opcao == 2) {
            string nome;

            cout << "Digite o nome do produto a ser removido: ";
            cin >> nome;

            deposito.removerProduto(nome);

        } else if(opcao == 3) {
            deposito.produtoMaiorValor();
        } else if(opcao == 4) {
            deposito.quantidadeProdutos();
        }else if(opcao == 5) {
            deposito.depositoVazio();
        }
    }   
    return 0;
}