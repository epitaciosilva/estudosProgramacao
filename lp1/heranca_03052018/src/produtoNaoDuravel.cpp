#include <iostream>
#include <string>
using namespace std;

#include "../include/produtoNaoDuravel.hpp"

ProdutoNaoDuravel::ProdutoNaoDuravel(){}

string ProdutoNaoDuravel::getDataValidade() {
   return this->dataValidade;
}

string ProdutoNaoDuravel::getGenero() {
   return this->genero;
}