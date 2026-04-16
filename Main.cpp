#include "Configuracion.hpp"
#include <iostream>
#include <limits>
#include <fstream>
#include <string>
using namespace std;

void ListaDeReproduccionActual();
void mostrarMenu();
Cancion ingresarCancion(const std::string& id1=""){
    Cancion c;
    if(id1.empty()){
        std::cout<< "ID: ";
        std::cin >> c.id;
    } else{
        c.id = id1;
    }
    std::cin.ignore();
    std::cout<<"Nombre Cancion: ";
    std::getline(std::cin,c.nombre_song);
    std::cout>>"Nombre albun: "
    std::getline(std::cin,c.nombre_album);
    std::cout<<"Año: ";
    std::cin>>c.years;
    std::cout<<"Duracion (segundos): ";
    std::cin>>c.duracion_seg;
    std::cin.ignore();
    std::cout<<"Ubicacion archivo: ";
    std::getline(std::cin,c.ubicacion_archivo);
    return c;
}
int main(){
    Configuracion config("status.cfg","music_source.txt");
    config.cargarCFG();
    if(!config.cargarTXT()){
        std::cout << "No se encontro archivo de canciones. Se creara uno nuevo." << std::endl;
    }
    String opcion :: tolower;
    do
    {
        config.mostrarUltimaCancionReproducida();
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
                config.mostrarTodasLasCanciones();
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
    cout << ""<<enld;
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