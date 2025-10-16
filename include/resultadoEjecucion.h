#ifndef RESULTADOEJECUCION_H
#define RESULTADOEJECUCION_H

#include <string>

using namespace std;
class ResultadoEjecucion {
private:
    string nombreAlgoritmo;
    int fragmentacionExterna;
    int huecosLibres;
    int mayorHueco;
    int fragmentacionInterna;

public:
    ResultadoEjecucion();
    ResultadoEjecucion(const string& nombre, int ext, int huecos, int maxHueco, int interna);

    string getNombre() const;
    int getFragmentacionExterna() const;
    int getHuecosLibres() const;
    int getMayorHueco() const;
    int getFragmentacionInterna() const;
};

#endif
