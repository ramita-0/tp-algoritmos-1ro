#include <iostream>
#include <stdio.h>
#include "file-utils.h"
#include "general-utils.h"
#include "../model/repartidor.model.h"
#include "../data-structures/lista-cola-pedidos.h"
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

void populateRepartidoresArrayAtStart(Repartidor repartidores[],int &cantidadRepartidoresActuales){
  const char* vehiculoFiles[] = {"./data/RepAuto.dat", "./data/RepMoto.dat", "./data/RepCamion.dat", "./data/RepCamioneta.dat"};
    int i = 0;
    Repartidor repartidorActual;

    for (const char* filename : vehiculoFiles) {
        FILE* file = fopen(filename, "rb");
        if (file) {
            while (fread(&repartidorActual, sizeof(Repartidor), 1, file)) {
                repartidores[i] = repartidorActual;
                i++;
            }
            fclose(file);
        }
    }

    cantidadRepartidoresActuales = i;
    ordenamientoDeRepartidores(repartidores, cantidadRepartidoresActuales);
}

void generarArchivoConPedidosNoEntregados(ListaColaPedidos* listaColaPedidos) {
  FILE *pedidosNoEntregadosFile = fopen("./data/PedidosNoEntregados.dat", "wb"); 
  while (listaColaPedidos != NULL) {
    NodoPedido* nodoPedidoActual = listaColaPedidos->colaPedidos->primero;
    while (nodoPedidoActual != NULL) {
      fwrite(&nodoPedidoActual->pedido, sizeof(Pedido), 1, pedidosNoEntregadosFile);
      nodoPedidoActual = nodoPedidoActual->siguiente;
    }
    listaColaPedidos = listaColaPedidos->siguienteCola;
  }
  fclose(pedidosNoEntregadosFile);
}