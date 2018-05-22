#ifndef _CICLO_H_
#define _CICLO_H_

class Ciclo {
    private:
        int ciclo;
        bool disponivel = true; 
    
    public:
        Ciclo();
        Ciclo(int ciclo);
        static vector<Ciclo> ciclos();
        int getCiclo();
        bool getDisponivel();
        void setCiclo(int ciclo);
        void setDisponivel(bool disponivel);
};
#endif