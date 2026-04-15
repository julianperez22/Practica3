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
    CompresorLZ78(int cap = 500);
    ~CompresorLZ78();
    void limpiarDiccionario();
    int comprimir(const std::string& texto, int* indices, char* caracteres);
    std::string descomprimir(int* indices, char* caracteres, int numPares);
};
#endif
