#include "configuracion.h"
#include "archivos.h"
#include <fstream>
#include <string>

// Definición de variables globales
int idcfg = -1;
bool cfgant = false;
bool reproduciendo = false;

void cargarCfg(Lista& lista, Lista& registros ) {
    std::ifstream archivo("data/status.cfg");
    if (!archivo.is_open()) {
        cfgant = false;
        if (lista.getStart() != nullptr) {
            lista.Cfg(lista.getStart());
        }
        return;
    }
    
    std::string linea;
    std::string id;
    std::string pausandoStr;
    std::string aleatorioStr;
    std::string repetirStr;
    
    getline(archivo, linea);
    id = linea.substr(linea.find('=') + 1);
    idcfg = std::stoi(id);
    
    getline(archivo, linea);
    pausandoStr = linea.substr(linea.find('=') + 1);
    reproduciendo = (pausandoStr == "true");
    
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
    int rep = std::stoi(repetirStr);
    if (rep < 0) rep = 0;
    if (rep > 2) rep = 2;
    lista.Cfgrep(rep);
    
    archivo.close();
    
    if (!id.empty()) {
        int id1 = std::stoi(id);
        Node* temp = lista.buscar(id1);
        if (temp != nullptr) {
            lista.Cfg(temp);
            cfgant = true;
            limpiaryagregaractual(registros, temp);                        
        } else {
            cfgant = false;
        }
    } else {
        if (lista.getStart() != nullptr) {
            lista.Cfg(lista.getStart());
        }
        cfgant = false;
    }
}

void guardarCfg(Lista& lista){
    if(lista.getActual()==nullptr)return;
    
    ofstream archivo("data/music_source.txt");
    archivo<<"id="<<lista.getActual()->id<<endl;
    archivo<<"reproduciendo="<<(reproduciendo ? "true" : "false")<<endl;
    archivo<<"modo aleatorio="<<(lista.getAleatorio() ? "true" : "false")<<endl;
    archivo<<"repeticion="<<lista.getRepeticion()<<endl;
    archivo.close();
}