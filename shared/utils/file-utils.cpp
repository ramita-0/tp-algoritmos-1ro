#include <iostream>
#include <stdio.h>
#include "../model/repartidor.model.h"
#include "./general-utils.h"
using namespace std;

void writeToFiles(Repartidor repartidores[], int size) {
  FILE *autoFile = fopen("./data/RepAuto.dat", "wb"); 
  FILE *motoFile = fopen("./data/RepMoto.dat", "wb"); 
  FILE *camionFile = fopen("./data/RepCamion.dat", "wb"); 
  FILE *camionetaFile = fopen("./data/RepCamioneta.dat", "wb"); 
  
  ordenamientoDeRepartidores(repartidores, size);

  for (int i = 0; i < size; i ++) {
    if(repartidores[i].vehiculo.tipo == AUTO) fwrite(&repartidores[i], sizeof(Repartidor), 1, autoFile);
    if(repartidores[i].vehiculo.tipo == MOTO) fwrite(&repartidores[i], sizeof(Repartidor), 1, motoFile);
    if(repartidores[i].vehiculo.tipo == CAMION) fwrite(&repartidores[i], sizeof(Repartidor), 1, camionFile);
    if(repartidores[i].vehiculo.tipo == CAMIONETA) fwrite(&repartidores[i], sizeof(Repartidor), 1, camionetaFile);
  }

  fclose(autoFile);
  fclose(motoFile);
  fclose(camionFile);
  fclose(camionetaFile);
}
