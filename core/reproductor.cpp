#include "reproductor.h"
#include "configuracion.h"
#include <iostream>

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

void mostrarMenu(Node* actual, Lista& lista) {
    std::string alas;
    std::string repe;
    
    if (lista.getAleatorio() == true) {
        alas = "S";
    } else {
        alas = "";
    }
    
    if (lista.getRepeticion() == 0) {
        repe = "";
    } else if (lista.getRepeticion() == 1) {
        repe = "R1";
    } else {
        repe = "RA";
    }
    
    system(CLEAR_SCREEN);
    
    if (cfgant != false && actual != nullptr) {
        std::cout << "Reproduciendo" << "(" << alas << "-" << repe << ")" << ":" << actual->nombre << std::endl;
        std::cout << "Artista: " << actual->artista << std::endl;
        std::cout << "Album: " << actual->album << "   [" << actual->year << "]" << std::endl;
    } else {
        std::cout << "Reproduccion Detenida" << std::endl;
    }
    
    std::cout << "" << std::endl;
    std::cout << "Opciones" << std::endl;
    std::cout << "W - Repoducir/Pausar" << std::endl;
    std::cout << "Q - Pista Anterior" << std::endl;
    std::cout << "E - Pista Siguiente" << std::endl;
    std::cout << "S - Activar/Desactivar modo aleatorio" << std::endl;
    std::cout << "R - Reproduccion (Desactivado/Repetir una/repetir todas)" << std::endl;
    std::cout << "A - Ver lista de reproduccion actual" << std::endl;
    std::cout << "L - Listado de canciones" << std::endl;
    std::cout << "X - Salir" << std::endl;
    std::cout << "Ingrese Opcion: " << std::endl;
}

void menu_2(Lista& registros, Node* actual, Lista& lista) {
    std::string alas;
    std::string repe;
    
    if (lista.getAleatorio() == true) {
        alas = "S";
    } else {
        alas = "";
    }
    
    if (lista.getRepeticion() == 0) {
        repe = "";
    } else if (lista.getRepeticion() == 1) {
        repe = "R1";
    } else {
        repe = "RA";
    }
    
    system(CLEAR_SCREEN);
    
    if (cfgant != false && actual != nullptr) {
        std::cout << "Actual" << "(" << alas << "-" << repe << ")" << ":" << actual->nombre << " - " << actual->album << std::endl;
    } else {
        std::cout << "Actual" << "(" << alas << "-" << repe << ")" << ":" << std::endl;
    }
    
    std::cout << "Lista de reproducción actual:" << std::endl;
    std::cout << "" << std::endl;
    
    if (lista.mostrar2() == 0) {
        std::cout << "Opciones:" << std::endl;
        std::cout << "V – Volver al menú principal" << std::endl;
    } else {
        std::cout << "Opciones:" << std::endl;
        std::cout << "S<num> - Saltar a la cancion seleccionada" << std::endl;
        std::cout << "V - Volver al menu principal" << std::endl;
    }
}

void menu_3(Lista& registros,Node* actual,Lista& lista){
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
    cout<<""<<endl;
    cout<<"Lista de reproducción actual:"<<endl;
    lista.mostrar();
    cout<<""<<endl;
    cout<<"Opciones:"<<endl;
    cout<<"R<num> - Reproducir canción seleccionada"<<endl;
    cout<<"A<num> - Agregar canción seleccionada al final de la lista de reproducción actual"<<endl;
    cout<<"N – Agregar canción al registro de canciones"<<endl;
    cout<<"D<num> – Eliminar canción seleccionada"<<endl;
    cout<<"V – Volver al menú principal"<<endl;
}

void pausar(Lista& lista) {
    Node* actual = lista.getActual();
    if (actual == nullptr) return;
    
    if (reproduciendo) {
        reproduciendo = false;
    } else {
        reproduciendo = true;
    }
}