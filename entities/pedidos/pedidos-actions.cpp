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
void buscarPedido(Repartidor punteroRepartidor, ListaColaPedidos* lista, ListaColaPedidos*& pedido);
void desencolar(listaColaPedidos*& lista->colaPedidos->primero,listaColaPedidos*& lista->colaPedidos->ultimo);

void asignarPedido(Repartidor repartidores[], int cantidadRepartidoresActuales) {
  int DniRepartidor;
  cout<<"DNI del repartidor a asignar:"<<endl;
  cin>> DniRepartidor;
  Repartidor* punteroRepartidor = buscarRepartidor(DniRepartidor,repartidores,cantidadRepartidoresActuales);
  if(punteroRepartidor != nullptr){
    ListaColaPedidos* pedido = NULL;
    buscarPedido(punteroRepartidor,lista,pedido);
    if(pedido != NULL){
      punteroRepartidor->listaPedidosEntregados->pedido = pedido;
    }
    else{
      cout<<"no hay pedidos para asignar"<<endl;
    }
  }

}
//TODO: fijarse el tema del puntero en repartidor, tambien se puede pasar por referencia un puntero ya creado
Repartidor* buscarRepartidor(int dniRepartidor, Repartidor repartidores[], int cantidadRepartidoresActuales)
{
  int i = 0;
  while(i < cantidadRepartidoresActuales && dniRepartidor != repartidores[i].dni)
  {
    i++;
  }
  if(i == cantidadRepartidoresActuales)
  {
    return nullptr;
  }
  else
  {
    Repartidor* punteroRepartidor = &repartidores[i];
    return punteroRepartidor;
  }
}

int buscarPedido(Repartidor* punteroRepartidor, ListaColaPedidos* lista, ListaColaPedidos*& pedido){

  while(lista->siguienteCola != NULL){
    if(lista->zona == punteroRepartidor->zona && lista->tipoVehiculo == punteroRepartidor->vehiculo.tipo){
      pedido = lista->colaPedidos->primero->pedido;
      desencolar(lista->colaPedidos->primero,lista->colaPedidos->ultimo);
      return;
    }
    else{
      lista = lista->siguienteCola;
    }
}
}

void desencolar(listaColaPedidos*& lista->colaPedidos->primero, listaColaPedidos*& lista->colaPedidos->ultimo){
  NodoPedido*p = lista->colaPedidos->primero;
  lista->colapedidos->primero = lista->colapedidos->primero->siguiente;
  delete p;
}