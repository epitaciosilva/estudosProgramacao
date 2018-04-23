#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

typedef struct {
    string descricao;
    int qtdRegist;
    int dependeRegist;
} Instrucao;

typedef struct {
    string instrucao;
    int ciclo;
} InstrucaoPorCiclo;

typedef struct {
    int ciclo;
    bool disponivel = true;
} Ciclo;

vector<Instrucao> inicializarInstrucoes();
vector<Ciclo> inicializarCiclos();
vector<string> split(string instrucao, char c1 = ' ', char c2 = ',', char c3 = '\n');
bool registradorLivre(string registrador);
void imprimirCiclo(int ciclo, string instrucao = " ");
void inserirDependencia(string registrador);
void dissponibilizarRegistradores(string registradores);
void removerInstrucao(vector<InstrucaoPorCiclo> *instrucoesCiclo, int posicao);
void realizarCiclo(vector<InstrucaoPorCiclo> instrucoesCiclo);
bool verificarInstrucaoLivre(vector<string> instrucao);

vector<string> registEmUso;
vector<Instrucao> todasInstrucoes = inicializarInstrucoes();
vector<Ciclo> ciclos = inicializarCiclos();

int main () {
    vector<string> linhas;
    vector<InstrucaoPorCiclo> instrucoesCiclo;
    string line;
    ifstream arquivo ("instrucoes.txt");
    //enquanto a proxima linha não estiver liberada, continue imprimindo a anterior.
    if(arquivo.is_open()) {
        while(getline(arquivo, line)) {
            linhas.push_back(line);
        }
    }    
    InstrucaoPorCiclo instrucaoPorCiclo;
    instrucaoPorCiclo.instrucao = linhas[0];
    instrucaoPorCiclo.ciclo = 2;
    InstrucaoPorCiclo instrucaoPorCiclo2;
    instrucaoPorCiclo2.instrucao = linhas[1];
    instrucaoPorCiclo2.ciclo = 1;
    instrucoesCiclo.push_back(instrucaoPorCiclo);
    instrucoesCiclo.push_back(instrucaoPorCiclo2);
    realizarCiclo(instrucoesCiclo);
    // for(int i = 0; i < linhas.size(); i++) {
    //     vector<string> instrucao = split(linhas[i]);
    //     if(verificarInstrucaoLivre(instrucao)) {
    //         InstrucaoPorCiclo instrucaoPorCiclo;
    //         instrucaoPorCiclo.instrucao = linhas[i];
    //         instrucaoPorCiclo.ciclo = 1;
    //         instrucoesCiclo.push_back(instrucaoPorCiclo);
    //         realizarCiclo(instrucoesCiclo);
    //         //enquanto a próxima instrucão não estiver livre.
    //         //|| (instrucoesCiclo.size() != 0 && i > 0)
    //         while((i == linhas.size() && instrucoesCiclo.size() != 0) || !verificarInstrucaoLivre(split(linhas[i+1]))) {
    //             realizarCiclo(instrucoesCiclo);
    //         }
    //     }
    // }
    return 0;
}

vector<Instrucao> inicializarInstrucoes() {
    Instrucao add, sub, beq, bne, lw, sw;
    add.descricao = "add";
    add.dependeRegist = 1;
    add.qtdRegist = 3;

    sub.descricao = "sub";
    sub.dependeRegist = 1;
    sub.qtdRegist = 3;

    beq.descricao = "beq";
    beq.dependeRegist = 2;
    beq.qtdRegist = 2;

    bne.descricao = "bne";
    bne.dependeRegist = 2;
    bne.qtdRegist = 2;
    
    lw.descricao = "lw";
    lw.dependeRegist = 1;
    lw.qtdRegist = 1;

    sw.descricao = "sw";
    sw.dependeRegist = 2;
    sw.qtdRegist = 2;

    vector<Instrucao> instrucoes;
    instrucoes.push_back(add);
    instrucoes.push_back(sub);
    instrucoes.push_back(beq);
    instrucoes.push_back(bne);
    instrucoes.push_back(lw);
    instrucoes.push_back(sw);

    return instrucoes;
}

vector<Ciclo> inicializarCiclos() {
    Ciclo iff, id, ex, mem, wb;

    iff.ciclo = 1;
    id.ciclo = 2;
    ex.ciclo = 3;
    mem.ciclo = 4;
    wb.ciclo = 5;

    vector<Ciclo> ciclos;
    ciclos.push_back(iff);
    ciclos.push_back(id);
    ciclos.push_back(ex);
    ciclos.push_back(mem);
    ciclos.push_back(wb);
    
    return ciclos;
}

vector<string> split(string instrucao, char c1, char c2, char c3) {
    vector<string> vetorString;
    string pedaco;

    for(auto caract:instrucao) {
        if(caract != c1 && caract != c2 && caract != c3) {
            pedaco += caract;
        }else if(pedaco != "") {
            vetorString.push_back(pedaco);
            pedaco = "";
        }
    }

    if(pedaco != "") {
        vetorString.push_back(pedaco);
    }

    return vetorString;
}

void imprimirCiclo(int ciclo, string instrucao) {
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

void inserirDependencia(string registrador) {
    registEmUso.push_back(registrador);
}

void dissponibilizarRegistradores(string instrucao) {
    //alterar quando for implementar o jump
    int tipoInstrucao = instrucao.find("$");
    string registrador = instrucao.substr(tipoInstrucao, 3);
    cout << registrador << endl;
    for(int i = 0; i < registEmUso.size(); i++) {
        if(registEmUso[i] == registrador) {
            registEmUso.erase(registEmUso.begin()+i);            
        } 
    } 
}

void removerInstrucao(vector<InstrucaoPorCiclo> *instrucoesCiclo, int posicao) {
    instrucoesCiclo->erase(instrucoesCiclo->begin()+posicao);
}

void realizarCiclo(vector<InstrucaoPorCiclo> instrucoesCiclo) {
    for(int j = 1; j < 6; j++) {
        for(int i = 0; i < instrucoesCiclo.size(); i++) {
            if(instrucoesCiclo[i].ciclo == j && ciclos[j-1].disponivel) {
                imprimirCiclo(j, instrucoesCiclo[i].instrucao);
                ciclos[j-1].disponivel = false;
                if(j == 4) {
                    dissponibilizarRegistradores(instrucoesCiclo[i].instrucao);
                } else if(j == 5) {
                    removerInstrucao(&instrucoesCiclo, i);
                }
            }
        }
        if(ciclos[j-1].disponivel) {
            imprimirCiclo(j);
        }
    }
    cout << "-------------" << endl;
}

bool registradorLivre(string registrador) {
    for(int i = 0; i < registEmUso.size(); i++) {
        if(registEmUso[i] == registrador) {
            return false;            
        } 
    }
    return true;
}

bool verificarInstrucaoLivre(vector<string> instrucao) {
    int contador = 0;
    for(int i = 1; i < instrucao.size(); i++) {
        if(registradorLivre(instrucao[i])){ 
            contador++;
        }
    }    

    for(int i = 0; i < todasInstrucoes.size(); i++) {
        if(instrucao[0] == todasInstrucoes[i].descricao && contador >= todasInstrucoes[i].qtdRegist) {
            return true;
        }    
    }
    return false;
}