#pragma once
#include "../model/repartidor.model.h"
#include "../data-structures/lista-cola-pedidos.h"

void writeToFiles(Repartidor[], int);

void populateRepartidoresArrayAtStart(Repartidor[],int &);

void generarArchivoConPedidosNoEntregados(ListaColaPedidos*);