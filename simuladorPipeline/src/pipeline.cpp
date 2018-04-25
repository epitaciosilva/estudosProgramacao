#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "../include/pipeline.hpp"
#include "../include/ciclo.hpp"
#include "../include/instrucao.hpp"

Pipeline::Pipeline() {
    this->todasInstrucoes = Instrucao::instrucoes();
    this->ciclos = Ciclo::ciclos(); 
}

bool Pipeline::verificarInstrucaoLivre(vector<string> instrucao) {
    int contador = 0;
    for(vector<int>::size_type i = 1; i < instrucao.size(); i++) {
        if(this->registradorLivre(instrucao[i])){ 
            contador++;
        }
    }    

    for(vector<int>::size_type i = 0; i < this->todasInstrucoes.size(); i++) {
        if((instrucao[0] == this->todasInstrucoes[i].getDescricao() && 
            contador >= this->todasInstrucoes[i].getQtdRegistradores()) || instrucao[0] == "jump") {
            return true;
        }    
    }
    
    return false;
}

bool Pipeline::registradorLivre(string registrador) {
    for(vector<int>::size_type i = 0; i < this->registradoresEmUso.size(); i++) {
        if(this->registradoresEmUso[i] == registrador) {
            return false;            
        } 
    }

    return true;
}

void Pipeline::imprimirCiclo(int ciclo, string instrucao) {
    switch(ciclo) {
        case 1: 
            cout << "IF: " << instrucao << endl;
            break;
        case 2: 
            cout << "ID: " << instrucao << endl;
            break;
        case 3: 
            cout << "EX: " << instrucao << endl;
            break;
        case 4: 
            cout << "MEM: " << instrucao << endl;
            break;
        case 5: 
            cout << "WB: " << instrucao << endl;
    }
}

void Pipeline::inserirDependencia(vector<string> instrucao) {
    for(vector<int>::size_type i = 0; i < this->todasInstrucoes.size(); i++) {
        if(instrucao[0] == this->todasInstrucoes[i].getDescricao()) {
            this->registradoresEmUso.push_back(instrucao[this->todasInstrucoes[i].getDependenciaRegistradores()]);
            // cout << instrucao[this->todasInstrucoes[i].getDependenciaRegistradores()] << endl;
            break;
        }
    }
}

void Pipeline::dissponibilizarRegistradores(string instrucao) {
	int tipoInstrucao;
    string registrador;

	if(instrucao.substr(0,3) != "sw ") {
	    tipoInstrucao = instrucao.find("$");
	    registrador = instrucao.substr(tipoInstrucao, 3);
	} else {
		tipoInstrucao = instrucao.rfind("$");
	    registrador = instrucao.substr(tipoInstrucao, 3);
	}

    for(vector<int>::size_type i = 0; i < this->registradoresEmUso.size(); i++) {
        if(this->registradoresEmUso[i] == registrador) {
            this->registradoresEmUso.erase(this->registradoresEmUso.begin()+i);            
        } 
    } 
}

void Pipeline::passarCiclos() {
    for(vector<int>::size_type i =0; i < this->instrucoesEmUso.size(); i++) {
        if(this->instrucoesEmUso[i].getCiclo().getCiclo() <= 5) {
            Ciclo ciclo = this->instrucoesEmUso[i].getCiclo();
            ciclo.setCiclo(ciclo.getCiclo()+1);
            this->instrucoesEmUso[i].setCiclo(ciclo);
        }
    }
}

void Pipeline::removerInstrucao(int posicao) {
    this->instrucoesEmUso.erase(this->instrucoesEmUso.begin()+posicao);
}

void Pipeline::realizarCiclo() {
    cout << "-------------" << endl;
    for(int j = 1; j < 6; j++) {
        for(vector<int>::size_type i = 0; i < this->instrucoesEmUso.size(); i++) {
            if(this->instrucoesEmUso[i].getCiclo().getCiclo() == j && this->ciclos[j-1].getDisponivel()) {
                imprimirCiclo(j, this->instrucoesEmUso[i].getInstrucao());
                this->ciclos[j-1].setDisponivel(false);
               
                if(j == 4 && this->instrucoesEmUso[i].getInstrucao().substr(0,4) != "jump") {
                    dissponibilizarRegistradores(this->instrucoesEmUso[i].getInstrucao());
                } else if(j == 5) {
                    removerInstrucao(i);
                }
            }
        }
        if(ciclos[j-1].getDisponivel()) {
            imprimirCiclo(j);
        }
    }
    this->ciclos = Ciclo::ciclos();
}

// gets and sets
vector<Instrucao> Pipeline::getInstrucoesEmUso() {
    return this->instrucoesEmUso;
}

void Pipeline::setInstrucoesEmUso(Instrucao instrucao) {
    this->instrucoesEmUso.push_back(instrucao);
}
