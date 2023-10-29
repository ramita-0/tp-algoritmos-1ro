#pragma once
#include "./cola-pedidos.h"
#include "../enum/vehiculos.enum.h"
using namespace std;

struct NodoArbol{
    int codigoComercio;
    int ventas;
    NodoArbol* izquierda;
    NodoArbol* derecha;
};