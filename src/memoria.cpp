#include "../include/Memoria.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

Memoria::Memoria(int tamanoTotal, AlgoritmoAsignacion* algoritmo)
    : tamanoTotal(tamanoTotal), algoritmo(algoritmo) {
    bloques.emplace_back(0, tamanoTotal, "");
}

Memoria::Memoria(const vector<int>& tamanosBloques, AlgoritmoAsignacion* algoritmo)
    : algoritmo(algoritmo) {
    int inicio = 0;
    tamanoTotal = 0;

    for (int i = 0; i < tamanosBloques.size(); i++) {
        bloques.emplace_back(inicio, tamanosBloques[i], "");
        inicio += tamanosBloques[i];
        tamanoTotal += tamanosBloques[i];
    }
}

void Memoria::asignar(const string& proceso, int tamano) {
    if (tamano <= 0) {
        cout << "Tamano inválido.\n";
    }
    else{
        int idx = algoritmo->seleccionarHueco(bloques, tamano);
        if (idx == -1) {
            cout << "No hay espacio suficiente para el proceso " << proceso << " (" << tamano << ").\n";
        }
        else{
            BloqueMemoria& b = bloques[idx];
            if (b.getTamanoDisponible() == tamano) {
                // ocupar todo el bloque
                b.setProceso(proceso, tamano);
                b.setTamanoDisponible(0);
            } else if (b.getTamano() > tamano) {
                // dividir: primer bloque para proceso, segundo bloque libre con el resto
                int tamLibre = b.getTamanoDisponible() - tamano;
                b.setProceso(proceso, tamano);
                b.setTamanoDisponible(tamLibre);
            }
        }
    }
}

void Memoria::liberar(const string& proceso) {
    int id = -1, bloque;
    for(int i = 0; i < bloques.size() && id == -1; i++){
        id = bloques[i].estaProceso(proceso);
        bloque = i;
    }
    if(id == -1){
        cout<<"El proceso no se encuetra asignado";
    }
    else{
        bloques[bloque].liberar(id);
    }
}

void Memoria::mostrar() const {
    cout << "\n===== ESTADO DE LA MEMORIA =====\n";
    cout << "Tamano total: " << tamanoTotal << " unidades\n";
    cout << "------------------------------------------\n";

    for (int i = 0; i < (int)bloques.size(); i++) {
        bloques[i].mostrar(i);
    }

    int externa, interna, huecos, mayor;
    calcularFragmentacion(externa, huecos, mayor, interna);

    cout << "Fragmentacion externa total: " << externa << endl;
    cout << "Huecos libres: " << huecos << endl;
    cout << "Bloque libre más grande: " << mayor << endl;
    cout << "Fragmentacion interna total: " << interna << endl;
    cout << "==========================================\n";
}



void Memoria::calcularFragmentacion(int &externa, int &huecos, int &mayor, int &interna) const {
    externa = 0;   // suma de bloques completamente libres
    interna = 0;   // suma del espacio libre dentro de bloques ocupados
    huecos = 0;    // cantidad de bloques libres
    mayor = 0;     // tamano del bloque libre más grande

    for (int i = 0; i < (int)bloques.size(); i++) {
        const BloqueMemoria& b = bloques[i];

        // Si el bloque está totalmente libre → cuenta como fragmentación externa
        if (b.estaLibre()) {
            externa += b.getTamano();
            huecos++;
            if (b.getTamano() > mayor)
                mayor = b.getTamano();
        }
        // Si tiene procesos, pero aún queda espacio → fragmentación interna
        else if (b.getTamanoDisponible() > 0) {
            interna += b.getTamanoDisponible();
        }
    }
}

