#include "compresorrle.h"

using namespace std;

CompresorRLE::CompresorRLE() {}

string CompresorRLE::comprimir(const string& texto) {
    if (texto.empty()) return "";

    string resultado = "";
    int n = texto.length();

    for (int i = 0; i < n; i++) {
        int conteo = 1;

        while (i < n - 1 && texto[i] == texto[i + 1]) {
            conteo++;
            i++;
        }

        resultado += to_string(conteo) + texto[i];
    }
    return resultado;
}

string CompresorRLE::descomprimir(const string& comprimido) {
    string resultado = "";
    int n = comprimido.length();

    for (int i = 0; i < n; i++) {
        string numStr = "";


        while (i < n && isdigit(comprimido[i])) {
            numStr += comprimido[i];
            i++;
        }

        if (numStr.empty() && i < n) {
            throw runtime_error("Error: Formato RLE invalido (falta el contador).");
        }

        if (i < n) {
            int veces = stoi(numStr);

            resultado.append(veces, comprimido[i]);
        }
    }
    return resultado;
}
