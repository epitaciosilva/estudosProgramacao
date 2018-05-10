#include <iostream>
#include <string>
using namespace std;

#include "../include/produtoDuravel.hpp"

string ProdutoDuravel::getMaterialPredominante() {
    return this->materialPredominante;
}

int ProdutoDuravel::getDurabilidade() {
    return this->durabilidade;
}
