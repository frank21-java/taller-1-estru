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

void cargarTxt(Lista& lista,Lista& registros);
bool reproduciendo=true;
void pausar(Lista& lista);
bool primero=false;
void registrar(Node* clonar,Lista& registros);
void guardarCfg(Node* actual);

int main(){
    Lista lista;
    Lista registros;
    cargarTxt(lista,registros);
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
            actual=lista.getActual();
            registrar(actual,registros);
            guardarCfg(actual);
        }
        else if (opcion == "e"){
            lista.siguiente();
            reproduciendo=true;
            actual=lista.getActual();
            registrar(actual,registros);
            guardarCfg(actual);
        }
        else if (opcion == "s") lista.alternarAleatorio();
        else if (opcion == "r") lista.repeticion();
        else if (opcion == "a") registros.mostrar();
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
    }
    else{
        cout<<"reanudando "<<actual->nombre<<endl;
        reproduciendo=true;
    }
}

void cargarTxt(Lista& lista,Lista& registros){
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
        if(primero==false) {
            Node* temp=new Node(stoi(id),nombre,artista,album,stoi(year),stoi(duracion),ruta);
            registros.agregar(temp); 
            primero=true;
            guardarCfg(nuevo);
        }
    }
    archivo.close();
}
void registrar(Node* clonar,Lista& registros){
    Node* clon=new Node(
        clonar->id,
        clonar->nombre,
        clonar->artista,
        clonar->album,
        clonar->year,
        clonar->duracion,
        clonar->ruta
        );
    registros.agregar(clon);
}
void guardarCfg(Node* actual){
    if(actual==nullptr)return;
    
    ofstream archivo("status.cfg");
    archivo<<"id="<<actual->id<<endl;
    archivo<<"nombre_cancion="<<actual->nombre<<endl;
    archivo<<"nombre_artista="<<actual->artista<<endl;
    archivo<<"nombre_album="<<actual->album<<endl;
    archivo<<"year="<<actual->year<<endl;
    archivo<<"duracion="<< actual->duracion<<endl;
    archivo<<"ubicacion_archivo="<<actual->ruta<<endl;
    archivo.close();
}