#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H
#include <string>

class Encriptador {
public:
    static unsigned char rotarIzquierda(unsigned char byte, int n);
    static unsigned char rotarDerecha(unsigned char byte, int n);
    static void procesar(std::string& datos, int n, unsigned char clave, bool encriptar);
};
#endif
