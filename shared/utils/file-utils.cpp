#include <iostream>
#include <stdio.h>
#include "file-utils.h"
#include "general-utils.h"
#include "../model/repartidor.model.h"
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

void lecturaArchivoRepartidores(Repartidor repartidores[],int &cantidadRepartidoresActuales){
  FILE *autoFile = fopen("./data/RepAuto.dat", "rb"); 
  FILE *motoFile = fopen("./data/RepMoto.dat", "rb"); 
  FILE *camionFile = fopen("./data/RepCamion.dat", "rb"); 
  FILE *camionetaFile = fopen("./data/RepCamioneta.dat", "rb");
  int i = 0;
  Repartidor r;
  
  fread(&r,sizeof(Repartidor),1,autoFile);
  while(!feof(autoFile))
  {
    repartidores[i] = r;
    i ++;
    fread(&r,sizeof(Repartidor),1,autoFile);
  }
  
  fread(&r,sizeof(Repartidor),1,motoFile);
  while(!feof(motoFile))
  {
    repartidores[i] = r;
    i ++;
    fread(&r,sizeof(Repartidor),1,motoFile);
  }

  fread(&r,sizeof(Repartidor),1,camionFile);
  while(!feof(camionFile))
  {
    repartidores[i] = r;
    i ++;
    fread(&r,sizeof(Repartidor),1,camionFile);
  }

  fread(&r,sizeof(Repartidor),1,camionetaFile);
  while(!feof(camionetaFile))
  {
    repartidores[i] = r;
    i ++;
    fread(&r,sizeof(Repartidor),1,camionetaFile);
  }
  cantidadRepartidoresActuales = i;
  ordenamientoDeRepartidores(repartidores,cantidadRepartidoresActuales);
}