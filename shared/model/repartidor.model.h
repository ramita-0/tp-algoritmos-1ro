#pragma once
#include <string>
#include "./vehiculo.model.h"
#include "../data-structures/nodo-pedido.model.h"
using namespace std;

struct Repartidor {
  string nombre;
  string apellido;
  int dni;
  int zona;
  Vehiculo vehiculo;
  NodoPedido* listaPedidosEntregados;

  void agregarPedido(Pedido pedido) {
    //TODO: Agregarlo ordenadamente
    if(this->listaPedidosEntregados == NULL) {
      this->listaPedidosEntregados = new NodoPedido;
      this->listaPedidosEntregados->pedido = pedido;
      this->listaPedidosEntregados->siguiente = NULL;
      return;
    }

    if(this->listaPedidosEntregados->siguiente == NULL) {
      this->listaPedidosEntregados->siguiente = new NodoPedido;
      this->listaPedidosEntregados->siguiente->pedido = pedido;
      this->listaPedidosEntregados->siguiente->siguiente = NULL;
      return;
    }

    NodoPedido* actual = listaPedidosEntregados;
    NodoPedido* anterior = listaPedidosEntregados;

    while(actual != NULL) {
      anterior = actual;
      actual = actual->siguiente;
    }

    anterior->siguiente = new NodoPedido;
    anterior->siguiente->pedido = pedido;
    anterior->siguiente->siguiente = NULL;
  }
};