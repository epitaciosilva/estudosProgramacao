#ifndef _PIPELINE_H_
#define _PIPELINE_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "./ciclo.hpp"
#include "./instrucao.hpp"

class Pipeline {
    private:
        vector<string> registradoresEmUso;
        vector<Instrucao> instrucoesEmUso;
        vector<Instrucao> todasInstrucoes;
        vector<Ciclo> ciclos;

    public:
        Pipeline();
        bool verificarInstrucaoLivre(vector<string> instrucao);
        bool registradorLivre(string registrador);
        void imprimirCiclo(int ciclo, string instrucao = " ");
        void inserirDependencia(string registrador);
        void dissponibilizarRegistradores(string registradores);
        void removerInstrucao(int posicao);
        void realizarCiclo();
        void passarCiclos();

        vector<Instrucao> getInstrucoesEmUso();
        void setInstrucoesEmUso(Instrucao instrucao);

};

#endif