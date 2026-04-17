#pragma once
#include "Cancion.h"
struct Node{
    Cancion datos;
    Node* next;
    Node(Cancion c);
}