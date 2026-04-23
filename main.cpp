#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include "compresorrle.h"
#include "compresorlz78.h"
#include "encriptador.h"

using namespace std;

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string leerDeArchivo(string nombre) {
    ifstream archivo(nombre, ios::in | ios::binary);
    if (!archivo.is_open()) return "";
    string contenido((istreambuf_iterator<char>(archivo)), istreambuf_iterator<char>());
    archivo.close();
    return contenido;
}

int main() {
    CompresorRLE motorRLE;
    CompresorLZ78 motorLZ78(1000);

    string textoUsuario = "";
    int indicesLZ78[1000];
    char caracteresLZ78[1000];
    int numParesLZ78 = 0;

    int n_rot, k_in;
    unsigned char claveK;
    int op1, op2, op3;

    while (true) {

        cout << "Datos" << endl;
        cout << "1. Abrir archivo\n2. Poner texto\n3. Cerrar" << endl;
        cout << "Opcion: ";
        if (!(cin >> op1)) { limpiarBuffer(); continue; }
        limpiarBuffer();

        if (op1 == 3) return 0;

        if (op1 == 1) {
            string nombre;
            cout << "Nombre del archivo: "; cin >> nombre;
            limpiarBuffer();
            textoUsuario = leerDeArchivo(nombre);
            if (textoUsuario.empty()) { cout << "No se encontro." << endl; continue; }
        } else if (op1 == 2) {
            cout << "Ingrese el texto: ";
            getline(cin, textoUsuario);
        } else continue;

        while (true) {
            cout << "\n" << endl;
            cout << "Escoja su metodo " << endl;
            cout << "Datos:  " << (textoUsuario.length() > 40 ? textoUsuario.substr(0, 40) + "..." : textoUsuario) << endl;
            cout << "1. RLE\n2. LZ78\n3. Encriptacion\n4. Volver\n5. Cerrar" << endl;
            cout << "Opcion: ";
            cin >> op2; limpiarBuffer();

            if (op2 == 5) return 0;
            if (op2 == 4) break;

            while (true) {
                cout << "\n Elige que hacer " << endl;
                string t1 = (op2 == 3) ? "Encriptar" : "Comprimir";
                string t2 = (op2 == 3) ? "Desencriptar" : "Descomprimir";
                cout << "1. " << t1 << "\n2. " << t2 << "\n3. Volver\n4. Cerrar" << endl;
                cout << "Opcion: ";
                cin >> op3; limpiarBuffer();

                if (op3 == 4) return 0;
                if (op3 == 3) break;

                if (op2 == 1) { // RLE
                    if (op3 == 1) textoUsuario = motorRLE.comprimir(textoUsuario);
                    else textoUsuario = motorRLE.descomprimir(textoUsuario);
                }
                else if (op2 == 2) {
                    if (op3 == 1) textoUsuario = motorLZ78.comprimir(textoUsuario, indicesLZ78, caracteresLZ78, numParesLZ78);
                    else textoUsuario = motorLZ78.descomprimir(indicesLZ78, caracteresLZ78, numParesLZ78);
                }
                else if (op2 == 3) {
                    while (true) {
                        cout << "Ingrese n: "; cin >> n_rot;
                        if (n_rot >= 0 && n_rot < 8) break;
                        cout << "Solo valores de 0 a 7." << endl;
                    }
                    cout << "Ingrese K (clave pal XOR 0-255): "; cin >> k_in;
                    limpiarBuffer();
                    claveK = (unsigned char)k_in;

                    if (op3 == 1) {

                        Encriptador::procesar(textoUsuario, n_rot, claveK, true);
                    } else {

                        string copia = textoUsuario;
                        Encriptador::procesar(copia, n_rot, claveK, false);

                        cout << "\nINTENTO DE DESENCRIPTACION: " << copia << endl;
                        cout << "Si es?  (s/n): ";
                        char confirm; cin >> confirm; limpiarBuffer();
                        if (confirm == 's' || confirm == 'S') textoUsuario = copia;
                        else cout << "No se guardo" << endl;
                    }
                }
                cout << "\n>>> RESULTADO FINAL: " << textoUsuario << endl;
            }
        }
    }
}
