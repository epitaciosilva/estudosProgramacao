#include <cstdlib>
#include <iostream>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

#include "sapo.h"

void mostrarGanhador(Sapo sapo) {
    cout << sapo.getIdentificador() << " Ganhour com " << sapo.getPulos() << " pulos" << endl;
}

int main() {
    int ganhador = -1;
    int distSapos[3] = {0, 0, 0};
    
    Sapo::distanciaTotal = 50;
    Sapo s1(1, 10);
    Sapo s2(2, 9);
    Sapo s3(3, 8);

    while(ganhador == -1) {
        distSapos[0] += s1.pular();
        distSapos[1] += s2.pular();
        distSapos[2] += s3.pular();
        
        if(distSapos[0] > Sapo::getDistanciaTotal()) { 
            mostrarGanhador(s1);
            ganhador = 0;
        } else if(distSapos[1] > Sapo::getDistanciaTotal()) { 
            mostrarGanhador(s2);
            ganhador = 0;
        } else if(distSapos[2] > Sapo::getDistanciaTotal()) {
            mostrarGanhador(s3);
            ganhador = 0;
        }
    }
    
    return 0;
}