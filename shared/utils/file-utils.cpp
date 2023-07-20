#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


void writeFiles(Repartidor v[], int size) {
  FILE *motoFile = fopen("../../data/RepMOTO.dat", "ab");
  FILE *autoFile = fopen("../../data/RepAuto.dat", "ab");
  FILE *camionFile = fopen("../../data/RepCamion.dat", "ab");
  FILE *camionetaFile = fopen("../../data/RepCamioneta.dat", "ab");

  for (int i = 0; i < size; i ++) {
    if (v[i].vehiculo.tipo == "MOTO") fwrite(&Repartidor, sizeof(Repartidor), 1, motoFile);
    if (v[i].vehiculo.tipo == "AUTO") fwrite(&Repartidor, sizeof(Repartidor), 1, autoFile);
    if (v[i].vehiculo.tipo == "CAMION") fwrite(&Repartidor, sizeof(Repartidor), 1, camionFile);
    if (v[i].vehiculo.tipo == "CAMIONETA") fwrite(&Repartidor, sizeof(Repartidor), 1, camionetaFile);
  }
}
