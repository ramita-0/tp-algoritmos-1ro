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
    //TODO: Agregarlo ordenadamente de menor a mayor por importe (REVISAR)
    if(this->listaPedidosEntregados == NULL) {
      this->listaPedidosEntregados = new NodoPedido;
      this->listaPedidosEntregados->pedido = pedido;
      this->listaPedidosEntregados->siguiente = NULL;
      return;
    }

    NodoPedido* actual = this->listaPedidosEntregados;
    NodoPedido* anterior = this->listaPedidosEntregados;
    NodoPedido* nuevoNodo = new NodoPedido;
    nuevoNodo->pedido = pedido;

    while(actual != NULL && actual->pedido.importe < pedido.importe) {
      anterior = actual;
      actual = actual->siguiente;
    }
    if (actual == this->listaPedidosEntregados) {
      nuevoNodo->siguiente = actual; 
      this->listaPedidosEntregados = nuevoNodo;
      return;
    }
    nuevoNodo->siguiente = actual;
    anterior->siguiente = nuevoNodo;
  }
};