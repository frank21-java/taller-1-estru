#include "Configuracion.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

Configuracion::Configuracion(const std::string& archivo) : nombreArchivo(archivo) {}