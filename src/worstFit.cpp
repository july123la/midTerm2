#include "../include/WorstFit.h"

int WorstFit::seleccionarHueco(const vector<BloqueMemoria>& memoria, int tamano) {
    int peorIdx = -1;
    int peorTam = -1;
    for (int i = 0; i < memoria.size(); ++i) {
        if (memoria[i].estaLibre()) {
            int tam = memoria[i].getTamano();
            if (tam >= tamano && tam > peorTam) {
                peorTam = tam;
                peorIdx = i;
            }
        }
    }
    return peorIdx;
}
