#include <iostream>
#include <stdio.h>
#include "../model/repartidor.model.h"
using namespace std;

void writeToFiles(Repartidor repartidores[], int size) {
  FILE *autoFile = fopen("./data/RepAuto.dat", "wb"); 
  FILE *motoFile = fopen("./data/RepMoto.dat", "wb"); 
  FILE *camionFile = fopen("./data/RepCamion.dat", "wb"); 
  FILE *camionetaFile = fopen("./data/RepCamioneta.dat", "wb"); 
  
  for (int i = 0; i < size; i ++) {
    if(repartidores[i].vehiculo.tipo == 0) fwrite(&repartidores[i], sizeof(Repartidor), 1, autoFile);
    if(repartidores[i].vehiculo.tipo == 1) fwrite(&repartidores[i], sizeof(Repartidor), 1, motoFile);
    if(repartidores[i].vehiculo.tipo == 2) fwrite(&repartidores[i], sizeof(Repartidor), 1, camionFile);
    if(repartidores[i].vehiculo.tipo == 3) fwrite(&repartidores[i], sizeof(Repartidor), 1, camionetaFile);
  }

  fclose(autoFile);
  fclose(motoFile);
  fclose(camionFile);
  fclose(camionetaFile);
}
  

