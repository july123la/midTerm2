#include "../include/BestFit.h"
#include <limits>

int BestFit::seleccionarHueco(const vector<BloqueMemoria>& memoria, int tamano) {
    int mejorIdx = -1;
    int mejorTam = numeric_limits<int>::max();
    for (int i = 0; i < memoria.size(); ++i) {
        int tam = memoria[i].getTamanoDisponible();
        if (tam >= tamano && tam < mejorTam) {
            mejorTam = tam;
            mejorIdx = i;
        }
    }
    return mejorIdx;
}
