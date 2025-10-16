#ifndef OPERACIONMANAGER_H
#define OPERACIONMANAGER_H

#include <vector>
#include <string>
#include "Operacion.h"

using namespace std;

class OperacionManager {
private:
    vector<Operacion> operaciones;

    string limpiarLinea(const string& linea) const;
    void cargarDesdeArchivo(const string& nombreArchivo);
    void cargarManual();

public:
    OperacionManager() = default;
    void procesarLinea(const string& linea);
    void cargarOperaciones(bool desdeArchivo);
    const vector<Operacion>& getOperaciones() const;
};

#endif
