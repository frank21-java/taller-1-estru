#include "data_structures/Lista.h"
#include "core/reproductor.h"
#include "core/configuracion.h"
#include "core/archivos.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    Lista lista;
    Lista registros;
    
    cargarTxt(lista, registros);
    cargarCfg(lista, registros);
    
    Node* actual;
    string opcion;
    
    do {
        actual = lista.getActual();
        mostrarMenu(actual, lista);
        cin >> opcion;
        
        if (opcion == "w") {
            pausar(lista);
        }
        else if (opcion == "q") {
            lista.anterior();
            reproduciendo = true;
            actual = lista.getActual();
            if (idcfg != actual->id) {
                registrar(actual, registros);
            } else {
                lista.siguiente();
                actual = lista.getActual();
            }
        }
        else if (opcion == "e") {
            lista.siguiente();
            reproduciendo = true;
            cfgant = true;
            actual = lista.getActual();
            if (actual == nullptr) {
                idcfg = -1;
            }
            registrar(actual, registros);
        }
        else if (opcion == "s") {
            lista.alternarAleatorio();
        }
        else if (opcion == "r") {
            lista.repeticion();
        }
        else if (opcion == "a") {
            string option2;
            do {
                menu_2(registros, actual, lista);
                cin >> option2;
                for (char &c : option2) {
                    c = toupper(c);
                }
                if (option2.length() > 1 && option2[0] == 'S') {
                    bool esNumero = true;
                    string numero;
                    for (size_t i = 1; i < option2.length(); i++) {
                        if (!isdigit(option2[i])) {
                            esNumero = false;
                            break;
                        }
                        numero += option2[i];
                    }
                    if (esNumero) {
                        for (int i = 0; i < stoi(numero); i++) {
                            lista.siguiente();
                            reproduciendo = true;
                            cfgant = true;
                            actual = lista.getActual();
                            if (actual == nullptr) {
                                idcfg = -1;
                            }
                            registrar(actual, registros);
                        }
                    } else {
                        cout << "Error: Ingrese un número después de S" << endl;
                    }
                }
            } while (option2 != "V");
        }
        else if (opcion == "l") {
            string option3;
            do {
                menu_3(registros, actual, lista);
                cin >> option3;
                for (char &c : option3) {
                    c = toupper(c);
                }
                
                if (option3.length() > 1 && option3[0] == 'R') {
                    bool esNumero = true;
                    string numero;
                    for (size_t i = 1; i < option3.length(); i++) {
                        if (!isdigit(option3[i])) {
                            esNumero = false;
                            break;
                        }
                        numero += option3[i];
                    }
                    if (esNumero) {
                        lista.buscar(stoi(numero));
                        reproduciendo = true;
                        actual = lista.getActual();
                        registrar(actual, registros);
                    } else {
                        cout << "Error: Ingrese un número después de R" << endl;
                    }
                }
                
                if (option3.length() > 1 && option3[0] == 'A') {
                    bool esNumero = true;
                    string numero;
                    for (size_t i = 1; i < option3.length(); i++) {
                        if (!isdigit(option3[i])) {
                            esNumero = false;
                            break;
                        }
                        numero += option3[i];
                    }
                    if (esNumero) {
                        lista.eliminar(stoi(numero));
                        registros.eliminar(stoi(numero));
                    } else {
                        cout << "Error: Ingrese un número después de A" << endl;
                    }
                }
                
                if (option3.length() == 1 && option3[0] == 'N') {
                    int idnew = lista.ultimaSong();
                    string nombre, artista, album, ruta;
                    int year, duracion;
                    
                    cout << "Nombre de la cancion: " << endl;
                    cin >> nombre;
                    cout << "Artista: " << endl;
                    cin >> artista;
                    cout << "Album: " << endl;
                    cin >> album;
                    cout << "Año: " << endl;
                    cin >> year;
                    cout << "Duracion (en segundos): " << endl;
                    cin >> duracion;
                    cout << "Ruta de la cancion: " << endl;
                    cin >> ruta;
                    
                    Node* nuevo = new Node(idnew, nombre, artista, album, year, duracion, ruta);
                    lista.agregar(nuevo);
                }
                
                if (option3.length() > 1 && option3[0] == 'D') {
                    bool esNumero = true;
                    string numero;
                    for (size_t i = 1; i < option3.length(); i++) {
                        if (!isdigit(option3[i])) {
                            esNumero = false;
                            break;
                        }
                        numero += option3[i];
                    }
                    if (esNumero) {
                        lista.eliminar(stoi(numero));
                        registros.eliminar(stoi(numero));
                    } else {
                        cout << "Error: Ingrese un número después de D" << endl;
                    }
                }
                
            } while (option3 != "V");
        }
        else if (opcion == "x") {
            break;
        }
        else {
            cout << "opcion invalida" << endl;
        }
    } while (opcion != "x");
    
    guardarCfg(lista);
    cout << "apagando..." << endl;
    
    return 0;
}