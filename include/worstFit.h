#ifndef WORSTFIT_H
#define WORSTFIT_H

#include "algortitmoAsignacion.h"

using namespace std;

class WorstFit : public AlgoritmoAsignacion {
public:
    int seleccionarHueco(const vector<BloqueMemoria>& memoria, int tamano) override;
};

#endif
