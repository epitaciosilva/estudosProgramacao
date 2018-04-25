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
    for(vector<float>::size_type i = 1; i < instrucao.size(); i++) {
        if(this->registradorLivre(instrucao[i])){ 
            contador++;
        }
    }    

    for(vector<float>::size_type i = 0; i < this->todasInstrucoes.size(); i++) {
        if(instrucao[0] == this->todasInstrucoes[i].getDescricao() && 
            contador >= todasInstrucoes[i].getQtdRegistradores()) {
            return true;
        }    
    }
    return false;
}

bool Pipeline::registradorLivre(string registrador) {
    for(vector<float>::size_type i = 0; i < this->registradoresEmUso.size(); i++) {
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

void Pipeline::inserirDependencia(string registrador) {
    this->registradoresEmUso.push_back(registrador);
}

void Pipeline::dissponibilizarRegistradores(string instrucao) {
    //alterar quando for implementar o jump
    int tipoInstrucao = instrucao.find("$");
    string registrador = instrucao.substr(tipoInstrucao, 3);
    for(vector<float>::size_type i = 0; i < this->registradoresEmUso.size(); i++) {
        if(this->registradoresEmUso[i] == registrador) {
            this->registradoresEmUso.erase(this->registradoresEmUso.begin()+i);            
        } 
    } 
}

void Pipeline::passarCiclos() {
    for(vector<float>::size_type i =0; i < this->instrucoesEmUso.size(); i++) {
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
    for(int j = 1; j < 6; j++) {
        for(vector<float>::size_type i = 0; i < this->instrucoesEmUso.size(); i++) {
            if(this->instrucoesEmUso[i].getCiclo().getCiclo() == j && this->ciclos[j-1].getDisponivel()) {
                imprimirCiclo(j, this->instrucoesEmUso[i].getInstrucao());
                this->ciclos[j-1].setDisponivel(false);
                if(j == 4) {
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
    cout << "-------------" << endl;
    ciclos = Ciclo::ciclos();
}

// gets and sets
vector<Instrucao> Pipeline::getInstrucoesEmUso() {
    return this->instrucoesEmUso;
}

void Pipeline::setInstrucoesEmUso(Instrucao instrucao) {
    this->instrucoesEmUso.push_back(instrucao);
}