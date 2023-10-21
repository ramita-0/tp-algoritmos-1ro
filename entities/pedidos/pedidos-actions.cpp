#include "./pedidos-actions.h"
using namespace std;
#include <iostream>
#include "../../shared/model/repartidor.model.h"
#include "../../shared/data-structures/cola-pedidos.h"
#include "../../shared/data-structures/lista-cola-pedidos.h"
#include "../../shared/data-structures/nodo-pedido.model.h"
#include "../../shared/utils/file-utils.h"
#include "../../shared/utils/general-utils.h"
#include "../../shared/utils/business-utils.h"

void ingresarPedido() {
  //...
}
Repartidor* buscarRepartidor(int dniRepartidor,Repartidor repartidores[], int cantidadRepartidoresActuales);
void buscarPedido(Repartidor* punteroRepartidor, ListaColaPedidos* lista, ListaColaPedidos*& punteroPedido);
void desencolar(ListaColaPedidos*& lista->colaPedidos->primero,ListaColaPedidos*& lista->colaPedidos->ultimo);

void asignarPedido(Repartidor repartidores[], int cantidadRepartidoresActuales) {
  int DniRepartidor;
  cout<<"DNI del repartidor a asignar:"<<endl;
  cin>> DniRepartidor;
  Repartidor* punteroRepartidor = buscarRepartidor(DniRepartidor,repartidores,cantidadRepartidoresActuales);
  if(punteroRepartidor != nullptr){
    ListaColaPedidos* punteroPedido = NULL;
    buscarPedido(punteroRepartidor,lista,punteroPedido);
    if(punteroPedido != NULL){ //encontro un pedido con esas caracteristicas
      punteroRepartidor->listaPedidosEntregados->pedido = punteroPedido->colaPedidos->primero->pedido;
    }
  
  else{
    cout<<"no hay pedidos para asignar"<<endl;
  }
  }
  else{
    cout<<"no existe el repartidor que buscas"<<endl;
  }
}

//TODO: fijarse el tema del puntero en repartidor, tambien se puede pasar por referencia un puntero ya creado
Repartidor* buscarRepartidor(int dniRepartidor, Repartidor repartidores[], int cantidadRepartidoresActuales){
  int i = 0;
  while(i < cantidadRepartidoresActuales && dniRepartidor != repartidores[i].dni)
  {
    i++;
  }
  if(i == cantidadRepartidoresActuales)
  {
    return nullptr; //no lo encontro
  }
  else
  {
    Repartidor* punteroRepartidor = &repartidores[i];
    return punteroRepartidor; //encontro el repartidor
  }
}

void buscarPedido(Repartidor* punteroRepartidor, ListaColaPedidos* lista, ListaColaPedidos*& punteroPedido){
  while(lista->siguienteCola != NULL){
    if(lista->zona == punteroRepartidor->zona && lista->tipoVehiculo == punteroRepartidor->vehiculo.tipo){
      punteroPedido->colaPedidos->primero->pedido = lista->colaPedidos->primero->pedido;
      desencolar(lista->colaPedidos->primero,lista->colaPedidos->ultimo);
      return;
    }
    else{
      lista = lista->siguienteCola;
    }
}
}

void desencolar(ListaColaPedidos*& lista->colaPedidos->primero, ListaColaPedidos*& lista->colaPedidos->ultimo){
  NodoPedido*p = lista->colaPedidos->primero;
  lista->colaPedidos->primero = lista->colaPedidos->primero->siguiente;
  delete p;
}