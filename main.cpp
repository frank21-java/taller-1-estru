#include "Node.h"
#include "Lista.h"

//#include "Configuracion.hpp"
#include <iostream>
//#include <limits>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
void mostrarMenu(Node* actual,Lista& lista);
void menu_2(Lista& registros,Node* actual,Lista& lista);
bool cfgant = false;
void cargarTxt(Lista& lista,Lista& registros);
bool reproduciendo=false;
void pausar(Lista& lista);
bool primero=false;
void registrar(Node* clonar,Lista& registros);
void guardarCfg(Lista& lista);
void cargarCfg(Lista& lista);
int idcfg;

int main(){
    Lista lista;
    Lista registros;
    Lista regis;
    cargarTxt(lista,registros);
    cargarCfg(lista);
    Node* actual;
    string opcion;
    do
    {
        actual=lista.getActual();
        mostrarMenu(actual,lista);
        cin >> opcion;
        if (opcion == "w") pausar(lista);
        else if (opcion == "q"){
            lista.anterior();
            reproduciendo=true;
            actual=lista.getActual();
            if(idcfg != actual->id){
                registrar(actual,registros);
            } else {
                lista.siguiente();
                actual=lista.getActual();
            }
        }
        else if (opcion == "e"){
            lista.siguiente();
            reproduciendo=true;
            cfgant = true;
            actual=lista.getActual();
            registrar(actual,registros);
        }
        else if (opcion == "s") lista.alternarAleatorio();
        else if (opcion == "r") lista.repeticion();
        else if (opcion == "a") {
            string option2;
            do{
                menu_2(registros,actual,lista);
                cin >> option2;
            } while (option2 != "v");
        }
        else if (opcion == "l") lista.mostrar();
        else if (opcion == "x") break;
        else {
            cout << "opcion invalida" << endl;
        }
    } while (opcion != "x");
    guardarCfg(lista);
    cout << "apagando..." << endl;
    return 0;
}

void menu_2(Lista& registros,Node* actual,Lista& lista){
    string alas;
    string repe;
    if(lista.getAleatorio() == true){
        alas = "S";
    } else{
        alas = "";
    }
    if(lista.getRepeticion() == 0){
        repe = "";
    } else if(lista.getRepeticion() == 1){
        repe = "R1";
    } else{
        repe = "RA";
    }
    system("clear");
    if (cfgant != false&& actual != nullptr){
        cout << "Actual"<<"("<< alas <<"-"<<repe<<")"<<":" << actual->nombre<<" - " <<actual->album<< endl;
    } else{
        cout << "Actual"<<"("<< alas <<"-"<<repe<<")"<<":"<< endl;
    }
    cout<<"Lista de reproducción actual:"<<endl;
    if(lista.mostrar2(registros) == false){
        cout<<"Opciones:"<<endl;
        cout<<"V – Volver al menú principal"<<endl;
    } else{
        cout<<"Opciones:"<<endl;
        cout<<"S<num> - Saltar a la canción seleccionada"<<endl;
        cout<<"V – Volver al menú principal"<<endl;
    }
}
void mostrarMenu(Node* actual, Lista& lista){
    string alas;
    string repe;
    if(lista.getAleatorio() == true){
        alas = "S";
    } else{
        alas = "";
    }
    if(lista.getRepeticion() == 0){
        repe = "";
    } else if(lista.getRepeticion() == 1){
        repe = "R1";
    } else{
        repe = "RA";
    }
    system("clear");
    if (cfgant != false&& actual != nullptr){
        cout << "Reproduciendo"<<"("<< alas <<"-"<<repe<<")"<<":" << actual->nombre<< endl;
        cout << "Artista: "   << actual->artista<<endl;
        cout << "Album: "  << actual->album<<"   ["<<actual->year<<"]"<<endl;
    }
    else{
        cout<<"Reproducción Detenida"<<endl;
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
    if(actual == nullptr) return;
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
            idcfg = stoi(id);
            primero=true;
        }
    }
    archivo.close();
}
void cargarCfg(Lista& lista){
	ifstream archivo("status.cfg");
	if(!archivo.is_open()){
	    cfgant = false;
	    if(lista.getStart() != nullptr){
	        lista.Cfg(lista.getStart());
	    }
		return;
	}
	string linea;
    string id;
    string pausandoStr;
    string aleatorioStr;
    string repetirStr;
	getline(archivo, linea);
    id = linea.substr(linea.find('=') + 1);
    idcfg = stoi(id);
    getline(archivo, linea);
    pausandoStr = linea.substr(linea.find('=') + 1);
    reproduciendo = (pausandoStr == "true"||pausandoStr == "false");
    
    getline(archivo, linea);
    aleatorioStr = linea.substr(linea.find('=') + 1);
    bool aleatorios;
    if (aleatorioStr == "true") {
        aleatorios = true;
    } else if (aleatorioStr == "false") {
        aleatorios = false;
    } else {
        aleatorios = false;
    }
    lista.Cfgala(aleatorios);
    
    getline(archivo, linea);
    repetirStr = linea.substr(linea.find('=') + 1);
    lista.Cfgrep(stoi(repetirStr));
    
    archivo.close();
    if(!id.empty()){
        int id1 = stoi(id);
        Node* temp = lista.buscar(id1);
        if(temp != nullptr){
            lista.Cfg(temp);
            cfgant = true;
        }else{
            cfgant = false;
        }
    }else{
        if(lista.getStart() != nullptr){
	        lista.Cfg(lista.getStart());
	    }
        cfgant = false;
    }
}
void registrar(Node* clonar,Lista& registros){
    if(clonar == nullptr)return;
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

void guardarCfg(Lista& lista){
    if(lista.getActual()==nullptr)return;
    
    ofstream archivo("status.cfg");
    archivo<<"id="<<lista.getActual()->id<<endl;
    archivo<<"reproduciendo="<<(reproduciendo ? "true" : "false")<<endl;
    archivo<<"modo aleatorio="<<(lista.getAleatorio() ? "true" : "false")<<endl;
    archivo<<"repeticion="<<lista.getRepeticion()<<endl;
    archivo.close();
}
