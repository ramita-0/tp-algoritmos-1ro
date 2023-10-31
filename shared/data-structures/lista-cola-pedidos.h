#pragma once
#include "./cola-pedidos.h"
#include "../enum/vehiculos.enum.h"
using namespace std;

struct ListaColaPedidos {
  Vehiculos tipoVehiculo;
  int zona; // 1 - 14
  ColaPedidos* colaPedidos;
  ListaColaPedidos* siguienteCola;

  ListaColaPedidos(Vehiculos tipoVehiculo, int zona, ColaPedidos* colaPedidos) {
    this->tipoVehiculo = tipoVehiculo;
    this->zona = zona;
    this->colaPedidos = colaPedidos;
    this->siguienteCola = NULL;
  }
};