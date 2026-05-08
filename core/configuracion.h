#pragma once
#include "../data_structures/Lista.h"

extern int idcfg;
extern bool cfgant;
extern bool reproduciendo;

void cargarCfg(Lista& lista,Lista& registros);
void guardarCfg(Lista& lista);