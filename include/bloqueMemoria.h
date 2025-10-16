#ifndef BLOQUEMEMORIA_H
#define BLOQUEMEMORIA_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class BloqueMemoria {
private:
    int inicio;          // Posición inicial del bloque
    int tamano;
    int tamanoDisponible;
    vector<pair<string, int>> procesos; // Nombre del proceso (vacío si está libre)

public:
    BloqueMemoria(int inicio, int  tamano, const string& proceso = "");

    // Getters
    int getInicio() const;
    int getTamano() const;
    int getTamanoDisponible() const;
    string getProceso() const;

    // Setters
    void setInicio(int inicio);
    void setTamano(int tamano);
    void setTamanoDisponible(int nuevo);
    void setProceso(const string& proceso, int tam);
    void liberar(int id);

    // Métodos funcionales
    int estaProceso(const string& proceso) const;
    void mostrar(int indice) const;
    bool estaLibre() const;
};

#endif
