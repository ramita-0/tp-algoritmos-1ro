#pragma once
#include "../../shared/data-structures/lista-cola-pedidos.h"
#include "../../shared/data-structures/nodo-arbol.h"
#include "../../shared/model/repartidor.model.h"

void ingresarPedido(Repartidor[], int, ListaColaPedidos*&);

void asignarPedido(Repartidor[], int, ListaColaPedidos*&, NodoArbol*&);

