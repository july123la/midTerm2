#ifndef ALGORITMOASIGNACION_H
#define ALGORITMOASIGNACION_H

#include <vector>
#include "BloqueMemoria.h"

class AlgoritmoAsignacion {
public:
    virtual ~AlgoritmoAsignacion() = default;
    virtual int seleccionarHueco(const std::vector<BloqueMemoria>& memoria, int tamano) = 0;
};

#endif
