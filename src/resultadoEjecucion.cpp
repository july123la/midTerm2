#include "../include/resultadoEjecucion.h"

ResultadoEjecucion::ResultadoEjecucion() {
    nombreAlgoritmo = "";
    fragmentacionExterna = huecosLibres = mayorHueco = fragmentacionInterna = 0;
}

ResultadoEjecucion::ResultadoEjecucion(const string& nombre, int ext, int huecos, int maxHueco, int interna) {
    nombreAlgoritmo = nombre;
    fragmentacionExterna = ext;
    huecosLibres = huecos;
    mayorHueco = maxHueco;
    fragmentacionInterna = interna;
}

std::string ResultadoEjecucion::getNombre() const { return nombreAlgoritmo; }
int ResultadoEjecucion::getFragmentacionExterna() const { return fragmentacionExterna; }
int ResultadoEjecucion::getHuecosLibres() const { return huecosLibres; }
int ResultadoEjecucion::getMayorHueco() const { return mayorHueco; }
int ResultadoEjecucion::getFragmentacionInterna() const { return fragmentacionInterna; }
