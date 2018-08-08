#include <iostream>
using namespace std;

#include "tempo.hpp"

Tempo::Tempo(int horas, int minutos, int segundos) {
    this->horas = horas;
    this->minutos = minutos;
    this->segundos = segundos;
}

Tempo::Tempo() {
    this->horas = 0;
    this->minutos = 0;
    this->segundos = 0;
}

int Tempo::getHoras() {
    return horas;
}

int Tempo::getMinutos() {
    return minutos;
}

int Tempo::getSegundos() {
    return segundos;
}

Tempo Tempo::operator+(Tempo &time) {
    int hrs = horas + time.getHoras();
    int min = minutos + time.getMinutos();
    int seg = segundos + time.getSegundos();

    return Tempo(hrs, min, seg);
}


void Tempo::impress() {
    cout << horas << ":" << minutos << ":" << segundos << endl;
}
