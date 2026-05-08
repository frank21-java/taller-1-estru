#include "Lista.h"
#include <iostream>
#include <random>
using namespace std;
Lista::Lista(){
    start=nullptr;
    actual=nullptr;
    aleatorio=false;
    songCfg=nullptr;
    repetir=0;
    cantidad=0;
}
void Lista::agregar(Node* nuevo){
    if(start==nullptr){
        start=nuevo;
        actual=nullptr;
        cantidad=1;
        return;
    }
    Node* nodoTemp=start;
    while(nodoTemp->next != nullptr){
        nodoTemp=nodoTemp->next;
    }
    nuevo->prev=nodoTemp;
    nodoTemp->next = nuevo;
    cantidad++;
}
bool Lista::mostrar(){
    if(start==nullptr){
        return false;
    }
    Node* nodoTemp=start;
    while(nodoTemp!=nullptr){
        cout<<nodoTemp->id<<". "<<nodoTemp->nombre<<" - "<<nodoTemp->artista<<endl;
        nodoTemp=nodoTemp->next;
    }
    return true;
}
int Lista::mostrar2() {
    if (actual == nullptr) {
        cout << "Vacia" <<endl;
        return 0;
    }
    Node* nodoTemp = actual;
    int contador = 0;
    
    while (nodoTemp != nullptr) {
    	if(nodoTemp != actual){
    		contador++;
        	cout << contador << ". " << nodoTemp->nombre << " - " << nodoTemp->artista << endl;
		}
        nodoTemp = nodoTemp->next;
    }
    
    return contador;
}
Node* Lista::buscar(int id){
    Node* nodoTemp=start;
    while(nodoTemp!=nullptr){
        if(nodoTemp->id==id) return nodoTemp;
        nodoTemp=nodoTemp->next;
    }
    return nullptr;
}
void Lista::eliminar(int id){
    if(start==nullptr) return;
    Node* nodoTemp=start;
    if(start->id==id){
        Node* temp=start;
        start=start->next;
        if(start) start->prev = nullptr;
        delete temp;
        cantidad--;
        return;
    }
    while(nodoTemp->next!=nullptr){
        if(nodoTemp->next->id==id){
        	Node* temp=nodoTemp->next;
        	nodoTemp->next= temp->next;
        	if(temp->next) temp->next->prev = nodoTemp;
        	delete temp;
        	cantidad--;
        	return;
    	}
        nodoTemp=nodoTemp->next;
    }
}
void Lista::siguiente() {
    if (repetir == 1) {
        return;
    }
    if (aleatorio) {
        if (actual && actual->next) {
            actual = actual->next;
        } else if (repetir == 2 && actual && actual->next == nullptr) {
            actual = generarRandom();
        }
    }  else {
        if (actual && actual->next) {
            actual = actual->next;
        }
        else if (repetir == 2 && actual && actual->next == nullptr) {
            actual = start;
        }
    }
}
void Lista::anterior(){
    if(repetir==1) return;
    if(actual && actual->prev){
        actual=actual->prev;
    }
    else{
        cout<<"este es el inicio de la lista"<<endl;
    }
}
Node* Lista::getActual(){
    return actual;
}
void Lista::alternarAleatorio(){
    if(aleatorio){
        this->aleatorio=false;
        cout<<"se desactivo el modo aleatorio"<<endl;
    }
    else{
        this->aleatorio=true;
        cout<<"se activo el modo aleatorio"<<endl;
    }
}
Node* Lista::generarRandom(){
	if (cantidad <= 1) return nullptr;
    int total = 0;
    Node* temp = actual;
    while (temp != nullptr) {
        total++;
        temp = temp->next;
    }
    Node** nodos = new Node*[total];
    
    temp = actual;
    for (int i = 0; i < total; i++) {
        nodos[i] = temp;
        temp = temp->next;
    }
    random_device rd;
    mt19937 gen(rd());
    for (int i = total - 1; i > 0; i--) {
        uniform_int_distribution<> dist(0, i);
        int j = dist(gen);
        Node* aux = nodos[i];
        nodos[i] = nodos[j];
        nodos[j] = aux;
    }
    for (int i = 0; i < total; i++) {
        if (i > 0) {
            nodos[i]->prev = nodos[i - 1];
            nodos[i - 1]->next = nodos[i];
        }
        if (i == total - 1) {
            nodos[i]->next = nullptr;
        }
    }
    
    Node* nuevoactual = nodos[0];
    delete[] nodos;
    return nuevoactual;
}
void Lista::repeticion(){
    if(repetir==0) repetir=1;
    else if(repetir==1) repetir=2;
    else repetir=0;
}
void Lista::Cfg(Node* cfg){
	actual = cfg;
	return;
}
void Lista::Cfgala(bool alator){
    this->aleatorio = alator;
    return;
}
void Lista::Cfgrep(int repet){
    this->repetir = repet;
    return;
}
bool Lista::getAleatorio(){
    return aleatorio;
}
int Lista::getRepeticion(){
    return repetir;
}
Node* Lista::getStart(){
    return start;
}
void Lista::limpiar(){
	Node* actual = start;
	while (actual != nullptr){
		Node* temp = actual;
		actual = actual->next;
		delete temp;
	}
	start = nullptr;
	cantidad = 0;
}
void Lista::Songfin(int id,Lista& lista){
    Node* nodo = lista.buscar(id);
    if (nodo == nullptr) {
        cout << "Canción no encontrada" << endl;
        return;
    }
    if (nodo->next == nullptr) {
        return;
    }
    if (nodo->prev != nullptr) {
        nodo->prev->next = nodo->next;
    } else {
        lista.start = nodo->next;
    }
    
    if (nodo->next != nullptr) {
        nodo->next->prev = nodo->prev;
    }
    Node* ultimo = lista.start;
    while (ultimo->next != nullptr) {
        ultimo = ultimo->next;
    }
    ultimo->next = nodo;
    nodo->prev = ultimo;
    nodo->next = nullptr;
    
}
void Lista::reproducirsong(int id){
    Node* nodoTemp=start;
    while(nodoTemp!=nullptr){
        if(nodoTemp->id==id) {
            actual = nodoTemp;
            return;
            }
        nodoTemp=nodoTemp->next;
    }
}
int Lista::ultimaSong(){
    int idsong = 0;
    if(start==nullptr){
        return 1;
    }
    Node* nodoTemp=start;
    while(nodoTemp!=nullptr){
        if(nodoTemp->id > idsong){
            idsong = nodoTemp->id;
        }
        nodoTemp=nodoTemp->next;
    }
    return idsong + 1;
}