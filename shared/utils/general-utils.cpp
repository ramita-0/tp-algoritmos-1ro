#include "../model/repartidor.model.h"

void generarSumatoriaVehiculosZona(int mat[5][14], Repartidor repartidores[], int cantidadRepartidoresActuales) {
  for (int i = 0; i < cantidadRepartidoresActuales; i ++){
    int zonaRepartidorActual = repartidores[i].zona;
    int vehiculoRepartidorActual = repartidores[i].vehiculo.tipo;

    mat[vehiculoRepartidorActual][zonaRepartidorActual - 1] ++;
  }
}