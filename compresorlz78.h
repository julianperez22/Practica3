#ifndef COMPRESORLZ78_H
#define COMPRESORLZ78_H

#include <iostream>
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

    CompresorLZ78(int capInicial = 500);
    ~CompresorLZ78();


    void limpiarDiccionario();
    void comprimir(const std::string& texto);



};

#endif
