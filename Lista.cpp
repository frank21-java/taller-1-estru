#include "Lista.h"
#include <iostream>
#include <random>
using namespace std;
Lista::Lista(){
    start=nullptr;
    actual=nullptr;
    aleatorio=false;
    repetir=0;
}
void Lista::agregar(Node* nuevo){
    if(start==nullptr){
        start=nuevo;
        actual=start;
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
void Lista::mostrar(){
    if(start==nullptr){
        cout << "lista vacia" <<endl;
        return;
    }
    Node* nodoTemp=start;
    while(nodoTemp!=nullptr){
        cout<<nodoTemp->id<<". "<<nodoTemp->nombre<<" - "<<nodoTemp->artista<<endl;
        nodoTemp=nodoTemp->next;
    }
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
        Node* temp=nodoTemp->next;
        start=start->next;
        delete temp;
        return;
    }
    while(nodoTemp->next!=nullptr){
        if(nodoTemp->next->id==id){
            Node* temp=nodoTemp->next;
            nodoTemp->next=temp->next;
            delete temp;
            return;
        }
        nodoTemp=nodoTemp->next;
    }
}

void Lista::siguiente(){
    if(repetir==1) return;
    if(aleatorio){
        for(int i=0;i<generarRandom();i++){
            if(actual->next==nullptr) actual=start;
            else actual=actual->next;
        }
    }
    else{
        if(actual && actual->next){
        actual=actual->next;
        }
        else{
            if(repetir==2) actual=actual->next;
            else cout<<"este es el fin de la lista"<<endl;
        }
    }
}
void Lista::anterior(){
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
int Lista::generarRandom(){
    int r;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,cantidad-1);
    r=dist(gen);
    return r;
}
void Lista::repeticion(){
    if(repetir==0) repetir=1;
    else if(repetir==1) repetir=2;
    else repetir=0;
}