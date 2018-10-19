#ifndef _ARVORE_N_ARIA_HPP
#define _ARVORE_N_ARIA_HPP

#include <vector>
#include <cstdlib>

template <typename T>
class Arvore {

    private: 
        std::vector<T> vet;
        int N;

    public: 
        Arvore() { }

        Arvore(int N) {
            this->vet.resize(1+N);
            this->N = N;
        }

        void resize() {
            this->vet.resize((int)this->vet.size()+N);
        }
        
        void addElemento(T elemento) {
            int iter = 0;
            int pai = 0;
            int cont = 1;
            
            while(true) {
                if(this->vet[iter] == 0) {
                    this->vet[iter] = elemento;
                    break;
                } else if(cont <= this->N) {
                    iter = 2*pai + cont;
                    cont++;
                } else if(cont > this->N && iter < (int)this->vet.size()-1) {
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

        int busca(T elemento) {
            int iter = 0;
            int pai = 0;
            int cont = 1;

            while(true) { 
                if(iter >= (int)this->vet.size()) {
                    return -1;
                } else if(this->vet[iter] == elemento) {
                    return iter;
                } else if(cont <= this->N)  {
                    iter = 2*pai +cont;
                    cont++;
                } else {
                    pai += 1;
                    cont = 0;
                    iter = 2*pai + cont;
                }
            }
        }

        void print() {
            std::cout << '\n';
            for(size_t i =0; i < this->vet.size(); i++) {
                std::cout << this->vet[i] << '\n';
            }
            std::cout << '\n';
        }
};

#endif