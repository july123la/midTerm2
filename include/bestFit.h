#ifndef BESTFIT_H
#define BESTFIT_H

#include "algortitmoAsignacion.h"

using namespace std;

class BestFit : public AlgoritmoAsignacion {
public:
    int seleccionarHueco(const vector<BloqueMemoria>& memoria, int tamano) override;
};

#endif
