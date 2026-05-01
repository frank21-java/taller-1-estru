#include "Lista.h"
#include <iostream>
using namespace std;
Lista::Lista(){
    start=nullptr;
}
void Lista::agregar(Node* nuevo){
    if(start==nullptr){
        start=nuevo;
        return;
    }
    Node* actual=start;
    while(actual->next != nullptr){
        actual=actual->next;
    }
    actual->next = nuevo;
}
void Lista::mostrar(){
    if(start==nullptr){
        cout << "lista vacia" <<endl;
        return;
    }
    Node* actual=start;
    while(actual!=nullptr){
        cout<<actual->id<<". "<<actual->nombre<<" - "<<actual->artista<<endl;
        actual=actual->next;
    }
}
Node* Lista::buscar(int id){
    Node* actual=start;
    while(actual!=nullptr){
        if(actual->id==id) return actual;
        actual=actual->next;
    }
    return nullptr;
}
void Lista::eliminar(int id){
    if(start==nullptr) return;
    Node* actual=start;
    if(start->id==id){
        Node* temp=actual->next;
        start=start->next;
        delete temp;
        return;
    }
    while(actual->next!=nullptr){
        if(actual->next->id==id){
            Node* temp=actual->next;
            actual->next=temp->next;
            delete temp;
            return;
        }
        actual=actual->next;
    }
}
bool Lista::vacia(){
    return start==nullptr;
}