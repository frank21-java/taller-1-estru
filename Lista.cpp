#include "Lista.h"
#include <iostream>
using namespace std;
Lista::Lista(){
    start=nullptr;
    actual=nullptr;
}
void Lista::agregar(Node* nuevo){
    if(start==nullptr){
        start=nuevo;
        return;
    }
    Node* nodoTemp=start;
    while(nodoTemp->next != nullptr){
        nodoTemp=nodoTemp->next;
    }
    nodoTemp->next = nuevo;
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
bool Lista::vacia(){
    return start==nullptr;
}

void Lista::siguiente(){
    if(actual && actual->next){
        actual=actual->next;
    }
}
void Lista::anterior(){
    if(actual && actual->prev){
        actual=actual->prev;
    }
}
Node* Lista::getActual(){
    return actual;
}