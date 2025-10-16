#include "../include/operacionManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

string OperacionManager::limpiarLinea(const string& linea) const {
    string sinComentario = linea;
    size_t pos = sinComentario.find("//");
    if (pos != string::npos)
        sinComentario = sinComentario.substr(0, pos);

    // quitar espacios al inicio
    size_t i = 0;
    while (i < sinComentario.length() && isspace(sinComentario[i]))
        i++;

    // quitar espacios al final
    int j = sinComentario.length() - 1;
    while (j >= 0 && isspace(sinComentario[j]))
        j--;

    if (i > j)
        return "";

    return sinComentario.substr(i, j - i + 1);
}

void OperacionManager::procesarLinea(const string& linea) {
    string limpia = limpiarLinea(linea);
    if (!limpia.empty()){
        istringstream iss(limpia);
        string cmd, proc;
        int tam = 0;

        iss >> cmd;
        if (cmd == "A" || cmd == "a") {
            iss >> proc >> tam;
            if (!proc.empty() && tam > 0) {
                operaciones.push_back(Operacion(cmd, proc, tam));
            } else {
                cout << "Línea inválida: " << limpia << "\n";
            }
        }
        else if (cmd == "L" || cmd == "l") {
            iss >> proc;
            if (!proc.empty()) {
                operaciones.push_back(Operacion(cmd, proc, 0));
            } else {
                cout << "Línea inválida: " << limpia << "\n";
            }
        }
        else if (cmd == "M" || cmd == "m") {
            operaciones.push_back(Operacion(cmd, "", 0));
        }
        else {
            cout << "Comando desconocido: " << cmd << "\n";
        }
    }
}


void OperacionManager::cargarDesdeArchivo(const string& nombreArchivo) {
    ifstream file(nombreArchivo);
    if (!file) {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << "\n";
        return;
    }

    string linea;
    while (getline(file, linea)) {
        procesarLinea(linea);
    }
}

void OperacionManager::cargarManual() {
    cout << "Ingrese operaciones (0 para terminar):\n";
    string linea;
    while (getline(cin, linea) && linea != "0") {
        procesarLinea(linea);   
    }
}

void OperacionManager::cargarOperaciones(bool desdeArchivo) {
    operaciones.clear();

    if (desdeArchivo) {
        string nombreArchivo;
        cout << "Ingrese el nombre del archivo de entrada: ";
        getline(cin, nombreArchivo);
        cargarDesdeArchivo(nombreArchivo);
    } else {
        cargarManual();
    }
}

const vector<Operacion>& OperacionManager::getOperaciones() const {
    return operaciones;
}
