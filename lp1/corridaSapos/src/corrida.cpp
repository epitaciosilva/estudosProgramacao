#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#include "../include/corrida.hpp"
#include "../include/pista.hpp"
#include "../include/sapo.hpp"

Corrida::Corrida() { }

Corrida::~Corrida() { }

void Corrida::inserirSaposPistas(std::vector<std::string> linhas) {
    size_t i = 1;

    //Enquanto a linha que sinaliza as pistas não chegar, continua lendo as informações dos sapos;
    while(linhas[i] != "PISTAS") {
        std::vector<std::string> atributos;
        std::string pedaco = "";

        //Pega carácter por carácter até encontrar o '-' ou o '\n' que sinalizam o termino de uma informação.
        for(auto caracter:linhas[i]) {
            if(caracter != '-' && caracter != '\n') {
                pedaco += caracter;
            }else if(pedaco != "") {
                atributos.push_back(pedaco);
                pedaco = "";
            }
        }

        if(pedaco != "") {
            atributos.push_back(pedaco);
        }
        
        //Alocando os atributos descritos no arquivo para um novo objeto Sapo;
        Sapo sapo(atributos[0], atributos[1]);
        this->sapos.push_back(sapo);
        i++;
    }
    
    //Pula a linha com a informação "PISTAS"
    i++;

    //Até chegar ao fim das linhas do arquivo, fica lendo as informações das pistas.
    while(i < linhas.size()) {
        std::vector<std::string> atributos;
        std::string pedaco = "";
        
        for(auto caracter:linhas[i]) {
            if(caracter != '-' && caracter != '\n') {
                pedaco += caracter;
            }else if(pedaco != "") {
                atributos.push_back(pedaco);
                pedaco = "";
            }
        }

        if(pedaco != "") {
            atributos.push_back(pedaco);
        }

        //Transformar std::string para inteiro.
        std::string::size_type sz;  
        int distancia = std::stoi(atributos[1], &sz);
        
        //Alocando os atributos descritos no arquivo para um novo objeto Pista.
        Pista pista(atributos[0], distancia);
        this->pistas.push_back(pista);
        i++;
    }

    this->imprimirSaposPistas();
} 

void Corrida::imprimirSaposPistas() {
    
    //Imprimir todos os sapos 
    for(size_t i = 0; i < this->sapos.size(); i++) {
        std::cout << "\n------ Sapo " << i+1 << " ------"<< std::endl;
        std::cout << "Descricao: " << this->sapos[i].getDescricao() << std::endl;
        std::cout << "Identificador: " << this->sapos[i].getIdentificador() << std::endl;
    }

    //Imprimir todas as pistas
    for(size_t i = 0; i < this->pistas.size(); i++) {
        std::cout << "\n------ Pista " << i+1 << " ------"<< std::endl;
        std::cout << "Descricao: " << this->pistas[i].getDescricao() << std::endl;
        std::cout << "Distancia: " << this->pistas[i].getDistancia() << std::endl;
    }
}

void Corrida::imprimirRank() {

    //Imprime o rank da corrida 
    for(size_t i = 0; i < this->classificacao.size(); i++) {
        std::cout << "\n------ " << i+1 << "° lugar------"<< std::endl;
        std::cout << "Sapo: " << this->classificacao[i].getDescricao() << std::endl;
        std::cout << "Identificador: " << this->classificacao[i].getIdentificador() << std::endl;
        std::cout << "Quantidade de pulos: " << this->classificacao[i].getQuantidadePulos() << std::endl;
        std::cout << "Distancia total percorrida: " << this->classificacao[i].getDistanciaPercorrida() << std::endl;

        //Não tem critério de desempate, então,
        //caso dê empate a quantidade de pulos com o que está na posição 0 (1°) 
        //também é considerado um vencedor.
        if(i == 0) {
            this->classificacao[i].posCorrida(true, false);
        } else if(i > 0 && this->classificacao[i].getQuantidadePulos() == this->classificacao[0].getQuantidadePulos()) {
            this->classificacao[i].posCorrida(true, true);
        }if(i+1 < this->classificacao.size() && this->classificacao[i].getQuantidadePulos() == this->classificacao[i+1].getQuantidadePulos()) { 
            this->classificacao[i].posCorrida(false, true);
        } else if(this->classificacao[i].getQuantidadePulos() == this->classificacao[i-1].getQuantidadePulos()) {
            this->classificacao[i].posCorrida(false, true);
        }
    }

}

void Corrida::iniciarCorrida() {
    
    for(size_t i = 0; i < this->sapos.size(); i++) {
        bool podePular = true;

        //Verificando se o sapo atual já terminou a corrida.
        for(size_t j = 0; j < this->classificacao.size(); j++) {
            if(this->sapos[i].getIdentificador() == this->classificacao[j].getIdentificador()) {
                podePular = false;
            }
        }

        //Caso o sapo ainda não teha terminado, ele pode continuar pulando.
        if(podePular) {
            this->sapos[i].pular();
            
            if(this->sapos[i].getDistanciaPercorrida() >= this->pistas[0].getDistancia()) {
                this->classificacao.push_back(this->sapos[i]);
            }
        }

        //Quando todos concluem a corrida.
        if(this->sapos.size() == this->classificacao.size()) {
            break;
        } else if(i+1 >= this->sapos.size()) {
            //Continuando a corrida após o último do vetor pular sem que todos tenham terminado a corrida.
            //-1 porque ao final do laço é incrementado o i++.
            i = -1;
        }
    }

    this->imprimirRank();
}