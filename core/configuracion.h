#pragma once
#include "../data_structures/Lista.h"

//Variables globales usadas en otras clases
extern int idcfg;
extern bool cfgant;
extern bool reproduciendo;

/**
 * Carga status.cfg para restaurar el programa a como estaba antes
 * 
 * @param lista Lista principal con todas las canciones
 * @param registros Lista con las canciones tocadas
 */
void cargarCfg(Lista& lista,Lista& registros);
/**
 * Guarda los datos del programa en status.cfg
 * 
 * @param lista La lista principal
 */
void guardarCfg(Lista& lista);