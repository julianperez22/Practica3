#include "compresorlz78.h"
#include <iostream>
#include <string>

using namespace std;


CompresorLZ78::CompresorLZ78(int capInicial) {
    capacidad = capInicial;
    tamanoActual = 0;
    diccionario = new EntradaDiccionario[capacidad];
}


CompresorLZ78::~CompresorLZ78() {
    delete[] diccionario;
}


void CompresorLZ78::limpiarDiccionario() {
    tamanoActual = 0; //Para borrar lo anterior
}


void CompresorLZ78::comprimir(const string& texto) {
    int n = texto.length();
    int indiceActual = 0;

    cout << "Salida " << endl;

    for (int i = 0; i < n; i++) {
        char car = texto[i];
        int encontradoEn = -1;


        for (int j = 0; j < tamanoActual; j++) {
            if (diccionario[j].prefijo == indiceActual && diccionario[j].nuevo == car) {
                encontradoEn = j + 1;
                break;
            }
        }

        if (encontradoEn != -1) {

            indiceActual = encontradoEn;
        } else {

            cout << "(" << indiceActual << ", '" << car << "') ";


            if (tamanoActual < capacidad) {
                diccionario[tamanoActual].prefijo = indiceActual;
                diccionario[tamanoActual].nuevo = car;
                tamanoActual++;
            }


            indiceActual = 0;
        }
    }


    if (indiceActual != 0) {
        cout << "(" << indiceActual << ", ' ')";
    }

}
