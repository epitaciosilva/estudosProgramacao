#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "../include/conta.hpp"
#include "../include/movimentacao.hpp"

Conta::Conta(){

}

Conta::Conta(string agencia, string numero, double limite, bool status) {
    this->agencia = agencia;
    this->numero = numero;
    this->limite = limite;
    this->status = status;
}

void Conta::deposito(double valor, bool transferir) {
    this->saldo += valor;
    if(this->saldo > this->limite) {
        this->saldo -= valor;
        this->mensagens("o deposito", false);
    } else {
        movimentacoes.push_back(new Movimentacao("credito", valor, "Deposito"));
        if(!transferir) {
            this->mensagens("Deposito", true); 
        }
    }
}

void Conta::saque(double valor, bool transferir) {
    if(valor > this->saldo) {
        this->mensagens("o saque", false);
    } else {
        this->saldo -= valor;
        movimentacoes.push_back(new Movimentacao("debito", valor, "Saque"));  
        if(!transferir) {
            this->mensagens("Saque", true);
        }
    }
}

void Conta::transferencia(Conta conta, double valor) {
    if(this->saldo >= valor && conta.getSaldo() + valor < conta.getLimite()) {
        this->saque(valor, true);
        conta.deposito(valor, true);
        this->mensagens("Transfencia", true);
    } else {
        this->mensagens("a transfencia", false);
    }
}

void Conta::mensagens(string descricao, bool sucesso) {
    if(sucesso) {
        cout << descricao << " realizado com sucesso!" << endl;
    } else {
        cout << "Não foi possivel realizar " << descricao << "!" << endl;
    }
}

double Conta::getSaldo() {
    return this->saldo;
}

double Conta::getLimite() {
    return this->limite;
}
