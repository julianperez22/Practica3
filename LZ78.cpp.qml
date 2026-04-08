#include "LZ78.h"
#include <iostream>

using namespace std;

int buscarEnDiccionario(EntradaLZ78* dict, int tam, int prefijoBuscado, char caracterBuscado) {
    for (int i = 0; i < tam; i++) {
        if (dict[i].prefijo == prefijoBuscado && dict[i].caracter == caracterBuscado) {
            return i + 1;
        }
    }
    return 0;
}

void comprimirLZ78(string texto) {
    int n = texto.length();

    EntradaLZ78* diccionario = new EntradaLZ78[n];
    int tamDiccionario = 0;

    int prefijoActual = 0;

    cout << << endl;

    for (int i = 0; i < n; i++) {
        char c = texto[i];

}
