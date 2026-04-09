#include <iostream>
#include <string>
#include "compresorrle.h"

using namespace std;

int main() {
    CompresorRLE motor;
    string textoUsuario = "";
    string resultado = "";
    int opcion = 0;
    int metodo = 0;

    cout << "Seleccione el metodo (RLE 1 - LZ78 2) " << endl;
    cin >> metodo;

    if (metodo == 1){
        while (opcion != 4) {

            cout << "1. Ingresar Texto\n2. Comprimir\n3. Descomprimir\n4. Salir" << endl;
            cout << "Opcion: ";
            cin >> opcion;
            cin.ignore();

            if (opcion == 1) {
                cout << "Ingrese texto: ";
                cin >> textoUsuario;
            }
            else if (opcion == 2) {

                if (textoUsuario.length() > 0) {
                    resultado = motor.comprimir(textoUsuario);
                    cout << "Resultado: " << resultado << endl;
                } else {
                    cout << "Error: El texto esta vacio." << endl;
                }
            }
            else if (opcion == 3) {

                bool formatoValido = true;
                if (resultado.length() == 0) {
                    formatoValido = false;
                }

                if (formatoValido) {

                    string recuperado = motor.descomprimir(resultado);
                    cout << "Recuperado: " << recuperado << endl;
                } else {
                    cout << "Error: No hay nada que descomprimir." << endl;
                }
            }
        }
        return 0;
    }

}




