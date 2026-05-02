#include "Node.h"
#include "Lista.h"

//#include "Configuracion.hpp"
#include <iostream>
//#include <limits>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void mostrarMenu(Node* actual);

void cargarTxt(Lista& lista);

int main(){
    Lista lista;
    cargarTxt(lista);
    
    string opcion;
    do
    {
        mostrarMenu(lista.getActual());
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
    cout << "apagando..." << endl;
    return 0;
}

void mostrarMenu(Node* actual){
    system("clear");
    if (actual!=nullptr){
        cout << "Reproducionedo " << actual->nombre<< endl;
        cout << "Artista: "   << actual->artista<<endl;
        cout << "Albun: "  << actual->album<<endl;
    }
    else{
        cout<<"No se esta reproduciendo nada"<<endl;
    }
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

void cargarTxt(Lista& lista){
    ifstream archivo("music_source.txt");
    if(!archivo.is_open()){
        cout<<"error al abrir el archivo"<<endl;
        return;
    }
    
    string linea;
    
    while(getline(archivo,linea)){
        if(linea.empty()) continue;
        
        stringstream ss(linea);
        string id, nombre, artista, album, year, duracion, ruta;
        
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, artista, ',');
        getline(ss, album, ',');
        getline(ss, year, ',');
        getline(ss, duracion, ',');
        getline(ss, ruta);
        
        Node* nuevo=new Node(stoi(id),nombre,artista,album,stoi(year),stoi(duracion),ruta);
        lista.agregar(nuevo);
    }
    archivo.close();
}