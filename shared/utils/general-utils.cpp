#include <iostream>
#include "../model/repartidor.model.h"

void generarSumatoriaVehiculosZona(int mat[4][14], Repartidor repartidores[], int cantidadRepartidoresActuales) {
  for (int i = 0; i < cantidadRepartidoresActuales; i ++){
    int zonaRepartidorActual = repartidores[i].zona;
    int vehiculoRepartidorActual = repartidores[i].vehiculo.tipo;

    mat[vehiculoRepartidorActual][zonaRepartidorActual] ++;
  }
}

void ordenamientoDeRepartidores(Repartidor repartidores[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (repartidores[j].dni > repartidores[j + 1].dni) {
        Repartidor temp = repartidores[j];
        repartidores[j] = repartidores[j + 1];
        repartidores[j + 1] = temp;
      }
    }
  }
  return;
}