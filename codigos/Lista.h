#pragma once
#include "Node.h"
/**
 * Lista enlazada que conecta los nodos de canciones
 */
class Lista{
    private:
        /** Nodo de inicio de la lista, no cambia */
        Node* start;
        /** Nodo para recorrer la lista, siempre cambia */
        Node* actual;
        /**  */
        Node* songCfg;
        /** Estado del modo aleatorio */
        bool aleatorio;
        /** Cantidad total de canciones en la lista */
        int cantidad;
        /** Estado del modo repeticion 
         * 0 = desactivado
         * 1 = se repite una misma cancion hasta desactivar
         * 2 = se repite toda la lista en bucle, en otras palabras al llegar al final se vuelve al inicio
         */
        int repetir;
    public:
        /**
         * Constructor de la lista, inicia todo en nullptr, false, 0, etc.
         */
        Lista();
        /**
         * Agrega una cancion a la lista, se llama mientras se lee el txt
         * 
         * @param nuevo La nueva cancion que se agrega
         */
        void agregar(Node* nuevo);
        /**
         * Imprime por pantalla toda la lista
         * 
         * @return false si esta vacia, true si no lo esta
         */
        bool mostrar();
        /**
         * Imprime la lista de canciones actuales
         * 
         * @param registros Lista que contiene las canciones que se han tocado hasta el momento
         * @return false si esta vacia, true si no lo esta
         */
        bool mostrar2(Lista& registros);
        /**
         * Recorre la lista en busca de un nodo especifico
         * 
         * @param id Id de la cancion a buscar
         * @return El nodo correspondiente a la cancion solicitada
         */
        Node* buscar(int id);
        /**
         * Busca y elimina una cancion especifica
         * 
         * @param id Id de la cancion a eliminar
         */
        void eliminar(int id);

        /**
         * Cambia la cancion actual a la siguiente de la lista, si es el final hace un return
         */
        void siguiente();
        /**
         * Cambia la cancion actual a la anterior de la lista, si es el inicio hace un return
         */
        void anterior();
        /**
         * Alterna entre true y false para determinar si el modo aleatorio esta o no activo
         */
        void alternarAleatorio();
        /**
         * Genera un numero aleatorio entre 1 y la cantidad de canciones de la lista
         * 
         * @return El numero generado
         */
        int generarRandom();
        /**
         * Alterna entre los modos de repeticion, si estaba en 0 se vuelve 1, si estaba en 1 se vuelve 2, si estaba en 2 se vuelve 0
         */
        void repeticion();
        //metodos de cfg
        void Cfg(Node* cfg);
        void Cfgala(bool alator);
        void Cfgrep(int repet);
        //getters
        bool getAleatorio();
        int getRepeticion();
        Node* getStart();
        Node* getActual();
};