#include "compresorlz78.h"
#include <iostream>

using namespace std;

CompresorLZ78::CompresorLZ78(int cap) : capacidad(cap), tamanoActual(0) {
    diccionario = new EntradaDiccionario[capacidad];
}

CompresorLZ78::~CompresorLZ78() { delete[] diccionario; }

void CompresorLZ78::limpiarDiccionario() { tamanoActual = 0; }

string CompresorLZ78::comprimir(const string& texto, int* indices, char* caracteres, int& numPares) {
    limpiarDiccionario();
    int n = static_cast<int>(texto.length());
    int indiceActual = 0;
    numPares = 0;
    string visual = "";

    for (int i = 0; i < n; i++) {
        char car = texto[i];
        int encontrado = -1;

        for (int j = 0; j < tamanoActual; j++) {
            if (diccionario[j].prefijo == indiceActual && diccionario[j].nuevo == car) {
                encontrado = j + 1;
                break;
            }
        }

        if (encontrado != -1) {
            indiceActual = encontrado;
        } else {
            indices[numPares] = indiceActual;
            caracteres[numPares] = car;


            if (numPares > 0) visual += ", ";
            visual += "(" + to_string(indiceActual) + ", " + car + ")";

            if (tamanoActual < capacidad) {
                diccionario[tamanoActual].prefijo = indiceActual;
                diccionario[tamanoActual].nuevo = car;
                tamanoActual++;
            }
            indiceActual = 0;
            numPares++;
        }
    }


    if (indiceActual != 0) {
        indices[numPares] = indiceActual;
        caracteres[numPares] = '\0';

        numPares++;
    }

    return visual;
}

string CompresorLZ78::descomprimir(int* indices, char* caracteres, int numPares) {
    string resultado = "";
    limpiarDiccionario();

    for (int i = 0; i < numPares; i++) {
        string frase = "";
        int tempIdx = indices[i];

        while (tempIdx > 0) {
            frase = diccionario[tempIdx - 1].nuevo + frase;
            tempIdx = diccionario[tempIdx - 1].prefijo;
        }

        if (caracteres[i] != '\0') {
            frase += caracteres[i];
        }

        resultado += frase;

        if (tamanoActual < capacidad) {
            diccionario[tamanoActual].prefijo = indices[i];
            diccionario[tamanoActual].nuevo = caracteres[i];
            tamanoActual++;
        }
    }
    return resultado;
}
