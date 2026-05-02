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
bool reproduciendo=true;
void pausar(Lista& lista);

int main(){
    Lista lista;
    cargarTxt(lista);
    Node* actual;
    string opcion;
    do
    {
        actual=lista.getActual();
        mostrarMenu(actual);
        cin >> opcion;
        if (opcion == "w") pausar(lista);
        else if (opcion == "q"){
            lista.anterior();
            reproduciendo=true;
        }
        else if (opcion == "e"){
            lista.siguiente();
            reproduciendo=true;
        }
        else if (opcion == "s") {
            
        }
        else if (opcion == "r") {
            
        }
        else if (opcion == "a") {
            
        }
        else if (opcion == "l") lista.mostrar();
        else if (opcion == "x") break;
        else {
            cout << "opcion invalida" << endl;
        }
    } while (opcion != "x");
    cout << "apagando..." << endl;
    return 0;
}

void mostrarMenu(Node* actual){
    //system("clear");
    if (reproduciendo){
        cout << "Reproduciendo " << actual->nombre<< endl;
        cout << "Artista: "   << actual->artista<<endl;
        cout << "Album: "  << actual->album<<endl;
    }
    else{
        cout<<"No se esta reproduciendo nada"<<endl;
    }
    cout << "Opciones" << endl;
    cout << "W - Repoducir/Pausar" << endl;
    cout << "Q - Pista Anterior" << endl;
    cout << "E - Pista Siguiente" << endl;
    cout << "S - Activar/Desactivar modo aleatorio" << endl;
    cout << "R - Reproduccion (Desactivado/Repetir una/repetir todas)" << endl;
    cout << "A - Ver lista de reproduccion actual" << endl;
    cout << "L - Listado de canciones" << endl;
    cout << "X - Salir" << endl;
    cout << "Ingrese Opcion: " <<endl;
}

void pausar(Lista& lista){
    Node* actual=lista.getActual();
    if(reproduciendo){
        cout<<"pausando "<<actual->nombre<<endl;
        reproduciendo=false;
        //return nullptr;
    }
    else{
        cout<<"reanudando "<<actual->nombre<<endl;
        reproduciendo=true;
        //return actual;
    }
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