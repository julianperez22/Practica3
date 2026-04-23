#include "compresorrle.h"
#include <string>

using namespace std;

CompresorRLE::CompresorRLE() {}


string CompresorRLE::comprimir(string texto) {
    if (texto.empty()) return "";
    string resultado = "";
    size_t n = texto.length();

    for (size_t i = 0; i < n; i++) {
        int contador = 1;
        while (i < n - 1 && texto[i] == texto[i + 1]) {
            contador++;
            i++;
        }

        resultado += to_string(contador) + "\"" + texto[i] + "\"";
    }
    return resultado;
}


string CompresorRLE::descomprimir(string texto) {
    if (texto.empty()) return "";

    string resultado = "";
    string numStr = "";

    for (size_t i = 0; i < texto.length(); i++) {

        if (texto[i] == '\"') {

            if (i + 1 < texto.length()) {
                char dato = texto[i + 1];
                int cantidad = stoi(numStr);

                for (int j = 0; j < cantidad; j++) {
                    resultado += dato;
                }

                numStr = "";
                i += 2;
            }
        }

        else if (isdigit(texto[i])) {
            numStr += texto[i];
        }
    }
    return resultado;
}
