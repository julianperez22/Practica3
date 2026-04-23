#ifndef COMPRESORLZ78_H
#define COMPRESORLZ78_H

#include <string>

struct EntradaDiccionario {
    int prefijo;
    char nuevo;
};

class CompresorLZ78 {
private:
    EntradaDiccionario* diccionario;
    int capacidad;
    int tamanoActual;

public:
    CompresorLZ78(int cap);
    ~CompresorLZ78();
    void limpiarDiccionario();

    std::string comprimir(const std::string& texto, int* indices, char* caracteres, int& numPares);
    std::string descomprimir(int* indices, char* caracteres, int numPares);
};

#endif
