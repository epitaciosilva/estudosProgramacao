#ifndef _ARVORE_N_ARIA_HPP
#define _ARVORE_N_ARIA_HPP

#include <vector>
#include <cstdlib>

template <typename T>
class Arvore {

    private: 
        int *vet;
        int N;
        int tamanho;

    public: 
        Arvore() { }

        Arvore(int N) {
            vet = (T*) std::calloc((1+N), sizeof(T));
            this->N = N;
            this->tamanho = 1+N;
        }

        void resize() {
            void* men = std::realloc(this->vet, this->tamanho + this->N);
            this->tamanho += this->N;

            if(men) {
                
            }
        }
        
        void addElemento(T elemento) {
            int iter = 0;
            int pai = 0;
            int cont = 1;

            while(true) {
                std::cout << cont << " " << iter << " " << pai << '\n';

                if(this->vet[iter] == 0) {
                    this->vet[iter] = elemento;
                    break;
                } else if(cont <= this->N) {
                    cont++;
                    iter = 2*pai + cont;
                } else if(cont > this->N && iter < this->tamanho-1) {
                    pai += 1;
                    cont = 1;
                    iter = 2*pai + cont;
                } else if(cont >= this->N) {
                    pai += 1;
                    cont = 1;
                    iter = 2*pai + cont;
                    this->resize();
                }
            } 

            this->print();
        }

        void print() {
            std::cout << '\n';
            for(int i =0; i < this->tamanho; i++) {
                std::cout << this->vet[i] << '\n';
            }
            std::cout << '\n';
        }
};

#endif