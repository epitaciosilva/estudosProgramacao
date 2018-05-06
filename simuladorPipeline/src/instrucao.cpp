#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "../include/instrucao.hpp"

Instrucao::Instrucao(){}

Instrucao::Instrucao(string instrucao, Ciclo) {
    this->instrucao = instrucao;
    this->ciclo = ciclo;
}

vector<Instrucao> Instrucao::instrucoes() {
    Instrucao add, sub, beq, bne, lw, sw, jump;
    add.setDescricao("add");
    add.setDependenciaRegistradores(1);
    add.setQtdRegistradores(3);

    sub.setDescricao("sub");
    sub.setDependenciaRegistradores(1);
    sub.setQtdRegistradores(3);

    beq.setDescricao("beq");
    beq.setDependenciaRegistradores(2);
    beq.setQtdRegistradores(3);

    bne.setDescricao("bne");
    bne.setDependenciaRegistradores(2);
    bne.setQtdRegistradores(3);
    
    lw.setDescricao("lw");
    lw.setDependenciaRegistradores(1);
    lw.setQtdRegistradores(1);

    sw.setDescricao("sw");
    sw.setDependenciaRegistradores(2);
    sw.setQtdRegistradores(2);

    jump.setDescricao("jump");
    jump.setDependenciaRegistradores(1);
    jump.setQtdRegistradores(-1);

    vector<Instrucao> instrucoes;
    instrucoes.push_back(add);
    instrucoes.push_back(sub);
    instrucoes.push_back(beq);
    instrucoes.push_back(bne);
    instrucoes.push_back(lw);
    instrucoes.push_back(sw);
    instrucoes.push_back(jump);

    return instrucoes;
}

void Instrucao::setDescricao(string descricao) {
    this->descricao = descricao;
}

void Instrucao::setQtdRegistradores(int qtdRegistradores) {
    this->qtdRegistradores = qtdRegistradores;
}

void Instrucao::setDependenciaRegistradores(int dependenciaRegistradores) {
    this->dependenciaRegistradores = dependenciaRegistradores;
}

void Instrucao::setCiclo(Ciclo ciclo) {
    this->ciclo = ciclo;
}

string Instrucao::getDescricao() {
    return this->descricao;
}

int Instrucao::getQtdRegistradores() {
    return this->qtdRegistradores;
}

int Instrucao::getDependenciaRegistradores() {
    return this->dependenciaRegistradores;
}

Ciclo Instrucao::getCiclo() {
    return this->ciclo;
}

string Instrucao::getInstrucao() {
    return this->instrucao;
}
void Instrucao::setInstrucao(string instrucao) {
    this->instrucao = instrucao;
}