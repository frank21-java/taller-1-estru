#include "Cancion.h"
Cancion::Cancion(int id, string nombre, string artista, string album, int year, int duracion, string ruta) {
    this->id = id;
    this->nombre = nombre;
    this->artista = artista;
    this->album = album;
    this->year = year;
    this->duracion = duracion;
    this->ruta = ruta;
}