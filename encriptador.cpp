#include "encriptador.h"
using namespace std;

unsigned char Encriptador::rotarIzquierda(unsigned char byte, int n) {
    return (byte << n) | (byte >> (8 - n));
}

unsigned char Encriptador::rotarDerecha(unsigned char byte, int n) {
    return (byte >> n) | (byte << (8 - n));
}

void Encriptador::procesar(string& datos, int n, unsigned char clave, bool encriptar) {
    for (size_t i = 0; i < datos.length(); i++) {
        unsigned char b = (unsigned char)datos[i];
        if (encriptar) {
            b = rotarIzquierda(b, n);
            b ^= clave;
        } else {
            b ^= clave;
            b = rotarDerecha(b, n);
        }
        datos[i] = (char)b;
    }
}
