#include "Node.h"
#include "Lista.h"

#include "Configuracion.hpp"
#include <iostream>
#include <limits>
#include <fstream>
#include <string>
using namespace std;

void ListaDeReproduccionActual();
void mostrarMenu();
void leerArchivo();
int main(){
    string opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;
        if (opcion == "w") {
            
        }
        else if (opcion == "q") {
            
        }
        else if (opcion == "e") {
            
        }
        else if (opcion == "s") {
            
        }
        else if (opcion == "r") {
            
        }
        else if (opcion == "a") {
            
        }
        else if (opcion == "l") {
            
        }
        else if (opcion == "x") break;
        else {
            cout << "opcion invalida" << endl;
        }
    } while (opcion != "x");

    return 0;
}

void mostrarMenu(){
    system("clear");
    cout << "Reproducionedo " << endl;
    cout << "Artista: "   << endl;
    cout << "Albun: "  << endl;
    cout << "Opciones" << endl;
    cout << "W - Repoducir/Pausar" << endl;
    cout << "Q - Pista Anterior" << endl;
    cout << "E - Pista Siguiente" << endl;
    cout << "S - Activar/Desactivar modo alatorio" << endl;
    cout << "R - Reproduccion (Desactivado/Repetir una/repetir todas)" << endl;
    cout << "A - Ver lista de reproccion actual" << endl;
    cout << "L - Listado de canciones" << endl;
    cout << "X - Salir" << endl;
    cout << "Ingrese Opcion: " <<endl;
}
void ListaDeReproduccionActual(){
    
}
