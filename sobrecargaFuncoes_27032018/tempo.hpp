#include <iostream>
using namespace std;

class Tempo {
    private: 
        int horas;
        int minutos;
        int segundos;    

    public:
        Tempo();
        Tempo(int horas, int minutos, int segundos);
        int getHoras();
        int getMinutos();
        int getSegundos();
        Tempo operator+(Tempo &time);
        void impress();
};

