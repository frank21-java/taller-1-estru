#pragma once
#include "Node.h"
#include "Cancion.h"
#include "Lista.h"

#include "Configuracion.hpp"
#include <iostream>
#include <limits>
#include <fstream>
#include <string>
using namespace std;
0
void ListaDeReproduccionActual();
void mostrarMenu();
void leerArchivo();
int main(){
    String opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;
        switch (opcion){
            case "w":
                break;
            case "q":
                break;
            case "e":
                break;
            case "s":
                break;
            case "r":
                break;
            case "a":
                break;
            case "l":
                break;
            case "x":
                break;
            default: cout<< "opcion invalida" << endl;
        }
    } while (opcion != "x");

    return 0;
}

void mostrarMenu(){
    system("clear");
    cout << "Reproducionedo " << enld;
    cout << "Artista: "   << enld;
    cout << "Albun: "  << enld;
    cout << "Opciones" << enld;
    cout << "W - Repoducir/Pausar" << enld;
    cout << "Q - Pista Anterior" << enld;
    cout << "E - Pista Siguiente" << enld;
    cout << "S - Activar/Desactivar modo alatorio" << enld;
    cout << "R - Reproduccion (Desactivado/Repetir una/repetir todas)" << enld;
    cout << "A - Ver lista de reproccion actual" << enld;
    cout << "L - Listado de canciones" << enld;
    cout << "X - Salir" << enld;
    cout << "Ingrese Opcion: "
}
void ListaDeReproduccionActual(){
    
}
