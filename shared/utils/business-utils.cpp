#include "business-utils.h"

bool zonaEsValida(int zona) {
    if (zona >= 1 && zona <= 14) return true;
    return false;
}

bool vehiculoEsValido(int vehiculo) {
    if (vehiculo >= 1 && vehiculo <= 4) return true;
    return false;
}

int determinarVehiculoDelPedido(Pedido pedido) {
  // TODO: Justificar los <= ya que no queda claro en el enunciado
  if (pedido.volumen < 0.005) return MOTO;
  if (pedido.volumen >= 0.005 && pedido.volumen < 0.02) return AUTO;
  if (pedido.volumen >= 0.02 && pedido.volumen < 8) return CAMIONETA;
  if (pedido.volumen >= 8) return CAMION;
}