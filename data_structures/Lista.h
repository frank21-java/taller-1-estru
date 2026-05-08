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
         * Busca la ultima cancion de la lista
         * 
         * @return El id de la ultima cancion de la lista
         */
        int ultimaSong();
        /**
         * Cambia la cancion actual a la siguiente de la lista, si es el final hace un return
         * 
         */
        void siguiente();
        /**
         * Cambia la cancion actual a la anterior de la lista, si es el inicio hace un return
         */
        void anterior();
        /**
         * Avanza en la lista hasta encontrar la cancion indicada
         * 
         * @param song Es el nodo que se quiere empezar a reproducir
         */
        void reproducirsong(int id);
        /**
         * Mueve una cancion seleccionada al final de la lista
         */
        void Songfin(int id,Lista& lista);
        /**
         * Reproduce una cancion en espesifico que nosotros le indiquemos por la terminal
         */
        void reproducirsong(int id);
        /**
         * Alterna entre true y false para determinar si el modo aleatorio esta o no activo
         */
        void alternarAleatorio();
        /**
         * Genera alatoriamente la canciones de la lista 
         * @return La lista de canciones       
         */
        Node* generarRandom();
        /**
         * Alterna entre los modos de repeticion, si estaba en 0 se vuelve 1, si estaba en 1 se vuelve 2, si estaba en 2 se vuelve 0
         */
        void repeticion();
        /**
         * Limpia la lista y la deja vacia
         */
        void limpiar();
        /**
         * Convierte el nodo actual de la lista en el dado por status.cfg
         * 
         * @param cfg El nodo que sera el nuevo actual
         */
		void Cfg(Node* cfg);
		/**
         * Establece el modo aleatorio a como estaba en status.cfg
         * 
         * @param alator true si estaba activo, false si no lo estaba
         */
		void Cfgala(bool alator);
		/**
         * Reestablece el estado del modo repeticion guardado en status.cfg
         * 
         * @param repet El estado anterior del modo repeticion
         */
		void Cfgrep(int repet);
		
		//getters
		bool getAleatorio();
		int getRepeticion();
		Node* getStart();
		Node* getActual();
};