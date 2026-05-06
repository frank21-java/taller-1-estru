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
        cout << "Vacia" <<endl;
        return false;
    }
    Node* nodoTemp=start;
    while(nodoTemp!=nullptr){
        cout<<nodoTemp->id<<". "<<nodoTemp->nombre<<" - "<<nodoTemp->artista<<endl;
        nodoTemp=nodoTemp->next;
    }
    return true;
}
bool Lista::mostrar2(Lista& registros){
    if(start==nullptr){
        return false;
    }else if(registros.start == nullptr){
        return false;
    }
    Node* nodoTemp=start;
    Node* temp = registros.start;
    bool a = false;
    int contador = 0;
    while(nodoTemp!=nullptr){
        a=false;
        while(temp!=nullptr){
            if(registros.buscar(nodoTemp->id)){
                a = true;
                break;
            }
            temp=temp->next;
        }
        if(a == false){
            cout<<nodoTemp->id<<" . "<<nodoTemp->nombre<<" - "<<nodoTemp->artista<<endl;
            contador++;
        }
        nodoTemp=nodoTemp->next;
    }
    if(contador == 0){
        return false;
    }
    return true;
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

void Lista::siguiente(){
    if(repetir==1) return;
    if(aleatorio){
    	if(cantidad>0){
    		for(int i=0;i<generarRandom();i++){
            if(actual->next==nullptr) actual=start;
            else actual=actual->next;
        	}
		}
    }
    else{
        if(actual && actual->next){
        actual=actual->next;
        }
        else{
            if(repetir==2) actual=start;
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
	if(cantidad <=1)return 0;
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