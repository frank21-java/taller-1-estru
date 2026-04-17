#include "Lista.h"
using namespace std;
Lista::Lista(){
    start=nullptr;
}
void Lista::agregar(Cancion c){
    Node* nuevo=new Node(c);
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
        cout<<actual->datos.id<<". "<<actual->datos.nombre<<" - "<<actual->artista<<endl;
        actual=actual->next;
    }
}
Node* Lista::buscar(int id){
    Node* actual=start;
    while(actual!=nullptr){
        if(actual->datos.id==id) return actual;
        actual=actual->next;
    }
    return nullptr;
}
void Lista::eliminar(int id){
    if(start==nullptr) return;
    if(start->datos.id==id){
        Node* temp=actual->next;
        start=start->next;
        delete temp;
        return;
    }
    Node* actual=start;
    while(actual->next!=nullptr){
        if(actual->next-datos.id==id){
            Node* temp=actual->next;
            actual->next=temp->next;
            delete temp;
            return;
        }
        actual=actual->next;
    }
}
bool Lista::vacia(){
    return cabeza==nullptr;
}