#include <iostream>
#include "compresorrle.h"

using namespace std;

int main() {
    CompresorRLE motor;
    string prueba = "AAABBBCCCDD";

    try {
        string comp = motor.comprimir(prueba);
        cout << "Comprimido: " << comp << endl;

        string desc = motor.descomprimir(comp);
        cout << "Descomprimido: " << desc << endl;

        if (prueba == desc) {
            cout << "Verificacion exitosa: El texto coincide." << endl;
        }
    } catch (const exception& e) {

        cerr << "Error detectado: " << e.what() << endl;
    }

    return 0;
}
