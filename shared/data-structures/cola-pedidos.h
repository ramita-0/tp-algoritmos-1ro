#pragma once
#include "nodo-pedido.model.h"
using namespace std;

struct ColaPedidos {
  NodoPedido* primero;
  NodoPedido* ultimo;

  ColaPedidos(NodoPedido* primero, NodoPedido* ultimo) {
    this->primero = primero;
    this->ultimo = ultimo;
  }
};
