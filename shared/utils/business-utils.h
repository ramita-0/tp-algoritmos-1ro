#pragma once
#include "../model/vehiculo.model.h"
#include "../model/pedido.model.h"

bool zonaEsValida(int);

bool vehiculoEsValido(int);

int determinarVehiculoDelPedido(Pedido pedido); 

string returnNombreVehiculo(Vehiculos vehiculo);
