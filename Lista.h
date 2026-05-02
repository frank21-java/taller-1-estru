#pragma once
#include "Node.h"

class Lista{
    private:
        Node* start;
        Node* actual;
        bool aleatorio;
        int cantidad;
        int repetir;
    public:
        Lista();
        
        void agregar(Node* nuevo);
        void mostrar();
        Node* buscar(int id);
        void eliminar(int id);

        void siguiente();
        void anterior();
        Node* getActual();
        void alternarAleatorio();
        int generarRandom();
        void repeticion();
};