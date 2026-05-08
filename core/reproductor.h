#pragma once
#include "../data_structures/Lista.h"

/**
 * Muestra las opciones disponibles del primer menu al usuario
 * 
 * @param actual El nodo actual de la lista
 * @param lista La lista principal con todas las canciones
 */
void mostrarMenu(Node* actual, Lista& lista);
/**
 * Submenu accedido con la opcion "a"
 * 
 * @param registros La lista con el registro de canciones tocadas
 * @param actual La cancion en que se encuentra la lista principal
 * @param lista La lista principal con todas las canciones
 */
void menu_2(Lista& registros, Node* actual, Lista& lista);
/**
 * Submenu accedido con la opcion "l"
 * 
 * @param registros Lista con las canciones tocadas hasta el momento
 * @param actual La cancion actual de la lista principal
 * @param lista Lista con todas las canciones
 */
void menu_3(Lista& registros, Node* actual, Lista& lista);
/**
 * Pausa/despausa la reproduccion
 * 
 * param lista Lista principal, se usa para verificar que no este vacia
 */
void pausar(Lista& lista);