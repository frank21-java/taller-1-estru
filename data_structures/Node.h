#pragma once
#include <string>
/**
 * Los nodos contienen los datos de cada cancion
 */
using namespace std;
struct Node{
    Node* next;
    int id;
    string nombre;
    string artista;
    string album;
    int year;
    int duracion;
    string ruta;
     /**
     * El constructor de un nodo, next y prev inician como nullptr
     * 
     * @param id ID de la cancion
     * @param nombre El titulo de la cancion
     * @param artista El artista que compuso la cancion
     * @param album El album al que pertenece la cancion
     * @param year El año de estreno de la cancion
     * @param duracion La duracion de la cancion
     * @param ruta La ubicacion del archivo, en esta ocasion no se usa pero igual se incluye
     */
    Node(int id, string nombre, string artista, string album, int year, int duracion, string ruta);
    Node* prev;
};