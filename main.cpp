#include <iostream>
#include <string>
#include <limits>
#include "compresorrle.h"
#include "compresorlz78.h"
#include "encriptador.h"

using namespace std;

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    CompresorRLE motorRLE;
    CompresorLZ78 motorLZ78(500);

    string textoUsuario = "";
    string resultadoRLE = "";
    int indicesLZ78[500];
    char caracteresLZ78[500];
    int numParesLZ78 = 0;

    int n_rot, k_in;
    unsigned char claveK;
    int metodo = 0, opcion = 0;


    cout << "Parte para encriptacion" << endl;
    cout << "Rotacion n: "; cin >> n_rot;
    cout << "Clave K: "; cin >> k_in;
    claveK = (unsigned char)k_in;
    limpiarBuffer();

    cout << "\nMetodo (1. RLE - 2. LZ78): ";
    cin >> metodo;
    limpiarBuffer();

    if (metodo == 1) {
        while (opcion != 4) {
            cout << "\n RLE \n1. Poner Texto\n2. Comprimir\n3. Descomprimir\n4. Salir\nOpcion: ";
            cin >> opcion; limpiarBuffer();

            if (opcion == 1) {
                cout << "Texto: "; getline(cin, textoUsuario);
            }
            else if (opcion == 2) {
                if (!textoUsuario.empty()) {

                    resultadoRLE = motorRLE.comprimir(textoUsuario);
                    cout << "Resultado Comprimido: " << resultadoRLE << endl;


                    Encriptador::procesar(resultadoRLE, n_rot, claveK, true);
                }
            }
            else if (opcion == 3) {
                if (!resultadoRLE.empty()) {
                    string temp = resultadoRLE;
                    Encriptador::procesar(temp, n_rot, claveK, false);
                    cout << "Texto Original: " << motorRLE.descomprimir(temp) << endl;
                }
            }
        }
    }
    else if (metodo == 2) {
        opcion = 0;
        while (opcion != 4) {
            cout << "\n LZ78 \n1. Poner Texto\n2. Comprimir\n3. Descomprimir\n4. Salir\nOpcion: ";
            cin >> opcion; limpiarBuffer();

            if (opcion == 1) {
                cout << "Texto: "; getline(cin, textoUsuario);
            }
            else if (opcion == 2) {
                if (!textoUsuario.empty()) {
                    motorLZ78.limpiarDiccionario();
                    numParesLZ78 = motorLZ78.comprimir(textoUsuario, indicesLZ78, caracteresLZ78);


                    string temp(caracteresLZ78, numParesLZ78);
                    Encriptador::procesar(temp, n_rot, claveK, true);
                    for(int i=0; i<numParesLZ78; i++) caracteresLZ78[i] = temp[i];
                }
            }
            else if (opcion == 3) {
                if (numParesLZ78 > 0) {
                    string temp(caracteresLZ78, numParesLZ78);
                    Encriptador::procesar(temp, n_rot, claveK, false);
                    for(int i=0; i<numParesLZ78; i++) caracteresLZ78[i] = temp[i];

                    cout << "Texto Original: " << motorLZ78.descomprimir(indicesLZ78, caracteresLZ78, numParesLZ78) << endl;
                }
            }
        }
    }
    return 0;
}
