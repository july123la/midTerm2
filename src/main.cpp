#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include "../include/firstFit.h"
#include "../include/bestFit.h"
#include "../include/worstFit.h"
#include "../include/Memoria.h"
#include "../include/OperacionManager.h"
#include "../include/resultadoEjecucion.h"

using namespace std;

AlgoritmoAsignacion* crearAlgoritmo(int tipo) {
    if (tipo == 1) return new FirstFit();
    if (tipo == 2) return new BestFit();
    if (tipo == 3) return new WorstFit();
    return new FirstFit();
}

string nombreAlgoritmo(int tipo) {
    if (tipo == 1) return "First Fit";
    if (tipo == 2) return "Best Fit";
    if (tipo == 3) return "Worst Fit";
    return "Desconocido";
}

Memoria configurarMemoria(AlgoritmoAsignacion* algoritmo) {
    cout << "\nDesea personalizar la memoria? (s/n): ";
    string resp;
    getline(cin, resp);
    vector<int> tamanos;
    if (!resp.empty() && (resp[0] == 's' || resp[0] == 'S')) {
        int numBloques;
        cout << "Ingrese la cantidad de bloques de memoria: ";
        cin >> numBloques;
        cin.ignore();

        tamanos.reserve(numBloques);
        int total = 0;

        for (int i = 0; i < numBloques; ++i) {
            int tam;
            cout << "Tamano del bloque " << (i + 1) << ": ";
            cin >> tam;
            cin.ignore();
            tamanos.push_back(tam);
            total += tam;
        }

        cout << "Memoria configurada con " << numBloques << " bloques (total " << total << " unidades).\n";
    }
    else{
        cout << "Configuracion por defecto: 4 bloques de 25 unidades (total 100).\n";
        tamanos.push_back(25);
        tamanos.push_back(25);
        tamanos.push_back(25);
        tamanos.push_back(25);
    }
    return Memoria(tamanos, algoritmo);
}

void mostrarResumenFinal(const vector<ResultadoEjecucion>& resultados) {
    cout << "\n====================== RESULTADOS COMPARATIVOS ======================\n";
    cout << left << setw(15) << "Algoritmo"
         << setw(20) << "Frag. Externa"
         << setw(20) << "Huecos Libres"
         << setw(20) << "Frag. Interna" << "\n";
    cout << string(70, '-') << "\n";

    for (size_t i = 0; i < resultados.size(); ++i) {
        cout << left << setw(15) << resultados[i].getNombre()
             << setw(20) << resultados[i].getFragmentacionExterna()
             << setw(20) << resultados[i].getHuecosLibres()
             << setw(20) << resultados[i].getFragmentacionInterna() << "\n";
    }
    cout << string(70, '=') << "\n";
}

int main() {
    cout << "===== Simulador de Asignación de Memoria =====\n";

    OperacionManager manager;
    cout << "\nSeleccione el modo de ingreso:\n";
    cout << "1. Cargar desde archivo\n";
    cout << "2. Ingresar manualmente\n";
    cout << "Opcion: ";
    int modo;
    cin >> modo;
    cin.ignore();

    manager.cargarOperaciones(modo == 1);

    vector<ResultadoEjecucion> resultados;
    bool continuar = true;

    while (continuar) {
        cout << "\nSeleccione el algoritmo a ejecutar:\n";
        cout << "1. First Fit\n";
        cout << "2. Best Fit\n";
        cout << "3. Worst Fit\n";
        cout << "4. Terminar y ver resultados\n";
        cout << "Opcion: ";
        int tipo;
        cin >> tipo;
        cin.ignore();

        continuar = (tipo != 4);
        if (continuar) {    
            if (tipo < 1 || tipo > 3) {
                cout << "Opción inválida.\n";
            }
            else {
                AlgoritmoAsignacion* algoritmo = crearAlgoritmo(tipo);
                Memoria memoria = configurarMemoria(algoritmo);

                cout << "\n--- Ejecutando " << nombreAlgoritmo(tipo) << " ---\n";

                const vector<Operacion>& ops = manager.getOperaciones();
                for (int i = 0; i < ops.size(); ++i) {
                    string cmd = ops[i].getComando();
                    if (cmd == "A" || cmd == "a")
                        memoria.asignar(ops[i].getProceso(), ops[i].getTamano());
                    else if (cmd == "L" || cmd == "l")
                        memoria.liberar(ops[i].getProceso());
                    else if (cmd == "M" || cmd == "m")
                        memoria.mostrar();
                }

                int ext, huecos, maxHueco, interna;
                memoria.calcularFragmentacion(ext, huecos, maxHueco, interna);

                resultados.push_back(ResultadoEjecucion(nombreAlgoritmo(tipo), ext, huecos, maxHueco, interna));

                cout << "\nFragmentación externa: " << ext << "\n";
                cout << "Huecos libres: " << huecos << "\n";
                cout << "Mayor hueco disponible: " << maxHueco << "\n";
                cout << "Fragmentación interna: " << interna << "\n";

                cout << "\n¿Desea probar otro algoritmo? (s/n): ";
                string resp;
                getline(cin, resp);
                if (resp.empty() || resp[0] == 'n' || resp[0] == 'N')
                    continuar = false;

                delete algoritmo; // liberar puntero
            }
            mostrarResumenFinal(resultados);
        }
    }
    return 0;
}
