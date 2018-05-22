#include <cstdlib>
#include <iostream>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

#include "../include/sapo.h"

void mostrarGanhador(Sapo sapo) {
    cout << "O sapo " << sapo.getIdentificador() << " Ganhour com " << sapo.getPulos() << " pulos" << endl;
}

int main() {
    Sapo::distanciaTotal = 50;
    Sapo s1(1, 10);
    Sapo s2(2, 9);
    Sapo s3(3, 8);

    while(true) {
        s1.pular();
        s2.pular();
        s3.pular();
        
        if(s1.getDistanciaPercorrida() > Sapo::getDistanciaTotal()) { 
            mostrarGanhador(s1);
            break;
        } else if(s2.getDistanciaPercorrida() > Sapo::getDistanciaTotal()) { 
            mostrarGanhador(s2);
            break;
        } else if(s3.getDistanciaPercorrida() > Sapo::getDistanciaTotal()) {
            mostrarGanhador(s3);
            break;
        }
    }
    
    return 0;
}