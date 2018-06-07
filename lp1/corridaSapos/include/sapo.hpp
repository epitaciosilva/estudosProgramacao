/**
* @author Epitácio Bessa
* @file sapo.hpp
* @sa https://github.com/epitaciosilva/cppClass/blob/corridaSapos/lp1/corridaSapos/include/sapo.hpp
* @since 29/05/18
* @date 07/06/18
* @brief Implementações dos métodos da classe corrida
* @detail asdasdasdasdadasdafasdfasd
*/


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
		int getDistanciaPercorrida();
		int getQuantidadePulos();
		std::string getIdentificador();
		std::string getDescricao();
		
		friend std::ostream& operator<< (std::ostream &o, Sapo sapo);

		static int distanciaTotalCorrida;
		static std::random_device rd;
		static std::mt19937 gen;
		static std::uniform_int_distribution<> dis;
};

#endif