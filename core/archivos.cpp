#include "archivos.h"
#include <fstream>
#include <sstream>
#include <iostream>

static bool primero = false;

void cargarTxt(Lista& lista, Lista& registros) {
    std::ifstream archivo("data/music_source.txt");
    if (!archivo.is_open()) {
        std::cout << "error al abrir el archivo" << std::endl;
        return;
    }
    
    std::string linea;
    
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        
        std::stringstream ss(linea);
        std::string id, nombre, artista, album, year, duracion, ruta;
        
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, artista, ',');
        getline(ss, album, ',');
        getline(ss, year, ',');
        getline(ss, duracion, ',');
        getline(ss, ruta);
        
        Node* nuevo = new Node(std::stoi(id), nombre, artista, album, std::stoi(year), std::stoi(duracion), ruta);
        lista.agregar(nuevo);
        
        if (primero == false) {
            Node* temp = new Node(std::stoi(id), nombre, artista, album, std::stoi(year), std::stoi(duracion), ruta);
            registros.agregar(temp);
            primero = true;
        }
    }
    archivo.close();
}

void registrar(Node* clonar, Lista& registros) {
    if (clonar == nullptr) return;
    
    Node* clon = new Node(
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

void limpiaryagregaractual(Lista& registros, Node* clonar){
	if(clonar == nullptr) return;
	registros.limpiar();
	
	Node* clon = new Node(
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