#pragma once
#include "./nodo-pedido.model.h"
using namespace std;

struct ColaPedidos {
    int vehiculo; // 1 a 4... podria prescindir de este campo, pero asi se acerca a un approach que escala mas
    NodoPedido* primero;
    NodoPedido* ultimo;
};