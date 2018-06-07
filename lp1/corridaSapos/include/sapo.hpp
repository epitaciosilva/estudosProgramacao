#ifndef _SAPOS_
#define _SAPOS_

#include <iostream>
#include <string>
#include <random>

class Sapo {
	private: 
		std::string descricao;
		std::string identificador;
		int distanciaPercorrida;
		int quantidadePulos; //quantidade de pulos em uma corrida.
		int quantidadeCorridas;
		int vitorias;
		int empates;
		int quantidadeTotalPulos; //quantidade de pulos em todas corridas.
		int impulsoMaximo;
			
	public: 
		Sapo();
		Sapo(std::string nome, std::string identificador); 
		~Sapo();
		
		void pular();
		void posCorrida(bool vitoria, bool empate);
		void setDistanciaPercorrida(int distanciaPercorrida);
		// void setDescricao(std::string descricao);
		// void setIdentificador(std::string identificador);
		int getDistanciaPercorrida();
		std::string getIdentificador();
		std::string getDescricao();
		
		static int distanciaTotalCorrida;
		static std::random_device rd;
		static std::mt19937 gen;
		static std::uniform_int_distribution<> dis;
};

#endif