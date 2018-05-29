#ifndef _SAPOS_
#define _SAPOS_

#include <iostream>
#include <string>

class Sapo {
	private: 
		std::string nome;
		int identificador;
		int distanciaPercorrida;
		int quantidadePulos; //quantidade de pulos em uma corrida.
		int quantidadeCorridas;
		int vitorias;
		int empates;
		int quantidadeTotalPulos; //quantidade de pulos em todas corridas.
		int impulsoMaximo;
			
	public: 
		Sapo();
		Sapo(
			std::string nome, int identificador, 
			int distanciaPercorrida, int quantidadePulos, 
			int quantidadeCorridas, int vitorias, 
			int empates, int quantidadeTotalPulos
			); 
		~Sapo();
		
		void pular();
		static std::uniform_int_distribution<> distancia;
		static int distanciaTotalCorrida;
};

#endif