#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "../include/arquivo.hpp"
#include "../include/ciclo.hpp"
#include "../include/instrucao.hpp"
#include "../include/pipeline.hpp"

int main() {
    vector<string> linhas = Arquivo::lerArquivo("./instrucoes.txt");
    Pipeline pipeline;
    Ciclo ciclo(1); 
	int contador = 0;
    for(vector<int>::size_type i = 0; i < linhas.size(); i++) {
        vector<string> linha = Arquivo::split(linhas[i] + " ");
        vector<string> proximaLinha;
       
        if(pipeline.verificarInstrucaoLivre(linha)) {
            Instrucao instrucao;
            instrucao.setInstrucao(linhas[i]);
            instrucao.setCiclo(ciclo);
            pipeline.setInstrucoesEmUso(instrucao);
            
            if(linha[0] != "beq" && linha[0] != "bne" && linha[0] != "jump") {
                pipeline.inserirDependencia(linha);
            }
            
            int j = -1;
            if(i+1 < linhas.size()) {
                proximaLinha = Arquivo::split(linhas[i+1]);
                if(proximaLinha[0] == "beq" || proximaLinha[0] == "bne") {
                    j = stoi(proximaLinha[3]);
                } else if(proximaLinha[0] == "jump") {
                    j = stoi(proximaLinha[1]);
                }
                
                if(j != -1) {
                    linhas.erase(linhas.begin()+i+2, linhas.begin()+j-1);
                }
            }
            
            pipeline.realizarCiclo();
            pipeline.passarCiclos();
			contador++;
            while((i+1 == linhas.size() && !pipeline.getInstrucoesEmUso().empty()) || (i+1 < linhas.size() && !pipeline.verificarInstrucaoLivre(Arquivo::split(linhas[i+1])))) {
                pipeline.realizarCiclo();
                pipeline.passarCiclos();
				contador++;
            }
        }
    }

	cout << "\nForam realizados " << contador << " ciclo(s)" << endl;
    return 0;
}
