#include "business-utils.h"

bool zonaEsValida(int zona) {
    if (zona >= 1 && zona <= 14) return true;
    return false;
}

bool vehiculoEsValido(int vehiculo) {
    if (vehiculo >= 1 && vehiculo <= 4) return true;
    return false;
}