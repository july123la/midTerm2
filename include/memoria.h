#ifndef MEMORIA_H
#define MEMORIA_H

#include <vector>
#include <string>
#include <iostream>
#include "BloqueMemoria.h"
#include "algortitmoAsignacion.h"

using namespace std;

class Memoria {
private:
    vector<BloqueMemoria> bloques;
    int tamanoTotal;
    AlgoritmoAsignacion* algoritmo;

public:
    // Constructor con tamano total
    Memoria(int tamanoTotal, AlgoritmoAsignacion* algoritmo);

    // Nuevo constructor con bloques personalizados
    Memoria(const vector<int>& tamanosBloques, AlgoritmoAsignacion* algoritmo);

    void asignar(const string& proceso, int tamano);
    void liberar(const string& proceso);
    void mostrar() const;
    void calcularFragmentacion(int &externa, int &huecos, int &mayor, int &interna) const;

};

#endif
