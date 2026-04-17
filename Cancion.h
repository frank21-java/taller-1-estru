#pragma once
using namespace std;
struct Cancion{
    int id;
    string nombre;
    string artista;
    string album;
    int year;
    int duracion;
    string ruta;
    Cancion(int id, string nombre, string artista, string album, int year, int duracion, string ruta);
}