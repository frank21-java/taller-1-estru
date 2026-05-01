#pragma once
#include <string>
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
    Node(int id, string nombre, string artista, string album, int year, int duracion, string ruta);
};