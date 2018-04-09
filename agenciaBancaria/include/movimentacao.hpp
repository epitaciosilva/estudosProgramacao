#ifndef _MOVIMENTACAO_H_
#define _MOVIMENTACAO_H_

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Movimentacao {
	private:
		string descricao;
		double valor;
		string indicacao;

	public:	
		Movimentacao(string descricao, double valor, string indicacao);
		string getDescricao();
		// double getValor();
		// string getIndicacao();
};
#endif