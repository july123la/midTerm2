#include "../include/Operacion.h"

Operacion::Operacion(const string& comando, const string& proceso, int tamano)
    : comando(comando), proceso(proceso), tamano(tamano) {}

string Operacion::getComando() const { return comando; }
string Operacion::getProceso() const { return proceso; }
int Operacion::getTamano() const { return tamano; }

void Operacion::setComando(const string& c) { comando = c; }
void Operacion::setProceso(const string& p) { proceso = p; }
void Operacion::setTamano(int t) { tamano = t; }
