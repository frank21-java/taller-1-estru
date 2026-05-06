#pragma once
#include "Node.h"

class Lista{
    private:
        Node* start;
        Node* actual;
        Node* songCfg;
        bool aleatorio;
        int cantidad;
        int repetir;
    public:
        Lista();
        
        void agregar(Node* nuevo);
        bool mostrar();
        bool mostrar2(Lista& registros);
        Node* buscar(int id);
        void eliminar(int id);

        void siguiente();
        void anterior();
        Node* getActual();
        void alternarAleatorio();
        int generarRandom();
        void repeticion();
        void Cfg(Node* cfg);
        void Cfgala(bool alator);
        void Cfgrep(int repet);
        bool getAleatorio();
        int getRepeticion();
        Node* getStart();
};