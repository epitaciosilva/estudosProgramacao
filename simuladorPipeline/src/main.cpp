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
    cout << linhas.empty() << endl;
    for(vector<float>::size_type i = 0; i < linhas.size(); i++) {
        if(pipeline.verificarInstrucaoLivre(Arquivo::split(linhas[i]))) {
            Instrucao instrucao;
            instrucao.setInstrucao(linhas[i]);
            Ciclo ciclo(1);
            instrucao.setCiclo(ciclo);
            pipeline.setInstrucoesEmUso(instrucao);
            pipeline.realizarCiclo();
            pipeline.passarCiclos();
            while((!pipeline.getInstrucoesEmUso().empty() && i+1 == linhas.size()) || (i+1<linhas.size() && !pipeline.verificarInstrucaoLivre(Arquivo::split(linhas[i+1])))) {
                pipeline.realizarCiclo();
                pipeline.passarCiclos();
            }
        }
    }

    return 0;
}