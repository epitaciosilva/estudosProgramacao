#ifndef _CONTA_H_
#define _CONTA_H_

#include <string>
#include <vector>
using namespace std;

#include "movimentacao.hpp"

class Conta {
	private:
		string agencia;
		string numero;
		double saldo;
		bool status;
		double limite;
		void mensagens(string descricao, bool sucesso);

	public:	
		std::vector<Movimentacao*> movimentacoes;
		Conta();
		Conta(string agencia, string numero, double limite, bool status = true);
		void deposito(double valor, bool transferir = false);
		void saque(double valor, bool transferir = false);
		void transferencia(Conta conta, double valor);
		double getSaldo();
		double getLimite();
};	

#endif