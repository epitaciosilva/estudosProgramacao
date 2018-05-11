#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../include/deposito.hpp"
#include "../include/produto.hpp"

Deposito::Deposito(){}

Deposito::~Deposito(){}

void Deposito::adicionarProduto(Produto produto) {
    this->estoque.push_back(produto);
}

void Deposito::removerProduto(string nome) {
    for(size_t i = 0; i < this->estoque.size(); i++) { 
        if(this->estoque[i].getNome() == nome) {
            this->estoque.erase(this->estoque.begin()+i);
            cout << "\nProduto removido com sucesso" << endl;
            return;
        }
    }    
    cout << "\nProduto não encontrador" << endl;;
}

void Deposito::quantidadeProdutos() {
    cout << "\nHá " << this->estoque.size() << " produtos" << endl;
}

void Deposito::depositoVazio() {
    if(this->estoque.size() == 0) {
        cout << "\nNão há produtos no deposito" << endl;
    } else { 
        cout << "\nHá produtos no deposito" << endl;
    }
}

void Deposito::produtoMaiorValor() {
    if(this->estoque.size() > 0) {
        double maiorValor = this->estoque[0].getPreco();
        Produto produtoMaiorValor = this->estoque[0];

        for(size_t i = 1; i < this->estoque.size(); i++) { 
            if(maiorValor < this->estoque[i].getPreco()) {
                maiorValor = this->estoque[i].getPreco();
                produtoMaiorValor = this->estoque[i];
            }
        } 

        cout << "\nO produto com maior valor é: ";
        cout << "\nNome: " << produtoMaiorValor.getNome();
        cout << "\nPreco: " << produtoMaiorValor.getPreco();
        cout << "\nMarca: " << produtoMaiorValor.getMarca() << endl;    

    } else {
        cout << "\nDeposito vazio";
    }
}