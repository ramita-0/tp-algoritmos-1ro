#pragma once
#include "../model/pedido.model.h"
using namespace std;

struct NodoPedido {
    Pedido pedido;
    NodoPedido* siguiente;
};