#pragma once
#include "../data_structures/Lista.h"

/**
 * Carga y almacena los datos de music_source.txt
 * 
 * @param lista La lista completa con todas las canciones
 * @param registros Una segunda lista para guardar datos de canciones que se tocan
 */
void cargarTxt(Lista& lista, Lista& registros);
/**
 * Registra una cancion en la lista registros
 * 
 * @param clonar Es la cancion que se quiere registrar
 * @param registros La lista en la que se quiere guardar la cancion
 */
void registrar(Node* clonar, Lista& registros);
/**
 * Limpia una lista y agrega la ultima cancion tocada
 * 
 * @param registros La lista que se quiere limpiar
 * @param actual El nodo actual de la lista que se quiere guardar en la lista limpiada
 */
void limpiaryagregaractual(Lista& registros, Node* actual);