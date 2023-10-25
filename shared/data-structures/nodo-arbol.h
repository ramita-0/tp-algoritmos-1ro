#pragma once
#include "./cola-pedidos.h"
#include "../enum/vehiculos.enum.h"
using namespace std;

struct nodoArbol{
    int codigoComercio;
    int ventas;
    nodoArbol* izquierda;
    nodoArbol* derecha;
};