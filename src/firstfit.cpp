#include "../include/FirstFit.h"

int FirstFit::seleccionarHueco(const vector<BloqueMemoria>& memoria, int tamano) {
    for (int i = 0; i < memoria.size(); ++i) {
        if (memoria[i].getTamanoDisponible() >= tamano) {
            return i;
        }
    }
    return -1;
}
