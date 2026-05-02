#pragma once
#include "Node.h"

class Lista{
    private:
        Node* start;
        Node* actual;
    public:
        Lista();
        
        void agregar(Node* nuevo);
        void mostrar();
        Node* buscar(int id);
        void eliminar(int id);
        bool vacia();
        
        void siguiente();
        void anterior();
        Node* getActual();
};