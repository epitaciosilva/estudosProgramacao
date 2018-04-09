#include <iostream>

#include "tempo.hpp"

int main() {
    Tempo r(12, 30, 0);
    Tempo t(01, 20, 0);
    

    Tempo s(r + t);
    s.impress();
    return 0;
}
