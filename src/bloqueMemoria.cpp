#include "../include/BloqueMemoria.h"
#include <iomanip>

BloqueMemoria::BloqueMemoria(int inicio, int tamano, const string& proceso)
    : inicio(inicio), tamano(tamano), tamanoDisponible(tamano){}

int BloqueMemoria::getInicio() const { return inicio; }
int BloqueMemoria::getTamano() const { return tamano; }
int BloqueMemoria::getTamanoDisponible() const { return tamanoDisponible; }

void BloqueMemoria::setInicio(int inicio) { this->inicio = inicio; }
void BloqueMemoria::setTamano(int tamano) { this->tamano = tamano; }
void BloqueMemoria::setTamanoDisponible(int nuevo) { this->tamanoDisponible = nuevo; }
void BloqueMemoria::setProceso(const string& proceso, int tam) { 
    procesos.push_back({proceso, tam});
}
void BloqueMemoria::liberar(int id){
    tamanoDisponible += procesos[id].second;
    procesos.erase(procesos.begin() + id);
}

int BloqueMemoria::estaProceso(const string& proceso) const {
    bool encontrado = false;
    int id;
    for(int i = 0; i < procesos.size() && !encontrado; i++){
        encontrado = procesos[i].first == proceso;
        id = i;
    }
    if(!encontrado)
        id = -1;
    return id;
}

bool BloqueMemoria::estaLibre() const {
    return procesos.size() == 0;
}

void BloqueMemoria::mostrar(int indice) const {
    cout << "Bloque " << setw(2) << indice + 1
         << " | Inicio: " << setw(4) << inicio
         << " | Tamano: " << setw(4) << tamano
         << " | Libre: " << setw(4) << tamanoDisponible << endl;

    if (procesos.empty()) {
        cout << "  Procesos: (vacio)\n";
    } else {
        cout << "  Procesos: ";
        for (int i = 0; i < (int)procesos.size(); i++) {
            cout << procesos[i].first << "(" << procesos[i].second << ")";
            if (i < (int)procesos.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    cout << "------------------------------------------\n";
}
