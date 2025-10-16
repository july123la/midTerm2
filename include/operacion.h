#ifndef OPERACION_H
#define OPERACION_H

#include <string>

using namespace std;

class Operacion {
private:
    string comando;
    string proceso;
    int tamano;

public:
    Operacion(const string& comando = "", const string& proceso = "", int tamano = 0);

    // Getters
    string getComando() const;
    string getProceso() const;
    int getTamano() const;

    // Setters
    void setComando(const string& c);
    void setProceso(const string& p);
    void setTamano(int t);
};

#endif
