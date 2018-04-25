#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "../include/arquivo.hpp"

Arquivo::Arquivo(){}

vector<string> Arquivo::lerArquivo(string nomeArquivo) {
    vector<string> linhas;
    string line;
    ifstream arquivo(nomeArquivo);
    
    if(arquivo.is_open()) {
        while(getline(arquivo, line)) {
            linhas.push_back(line);
        }
    }  
    
    arquivo.close();
    return linhas;
}

vector<string> Arquivo::split(string instrucao, char c1, char c2, char c3) {
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
