#ifndef FIRSTFIT_H
#define FIRSTFIT_H

#include "algortitmoAsignacion.h"

using namespace std;

class FirstFit : public AlgoritmoAsignacion {
public:
    int seleccionarHueco(const vector<BloqueMemoria>& memoria, int tamano) override;
};

#endif
