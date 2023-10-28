#pragma once
#include "nodo-pedido.model.h"
using namespace std;

struct ColaPedidos {
  NodoPedido* primero;
  NodoPedido* ultimo;

  ColaPedidos(NodoPedido* primero, NodoPedido* ultimo) {
    this->primero = primero;
    this->ultimo = ultimo;
  }

  void agregarPedido(Pedido pedido) {
    // 0 nodos
    if (this->primero == NULL) {
      this->primero = new NodoPedido;
      this->primero->pedido = pedido;
      this->primero->siguiente = NULL;
      this->ultimo = NULL;
      return;
    }
    // 1 nodo
    if (this->ultimo == NULL) {
      this->ultimo = new NodoPedido;
      this->ultimo->pedido = pedido;
      this->ultimo->siguiente = NULL;
      this->primero->siguiente = this->ultimo;
      return;
    }
    // mas de un nodo
    NodoPedido* actual = this->primero;
    NodoPedido* anterior = this->primero;

    while (actual != NULL) {
      anterior = actual;
      actual = actual->siguiente;
    }
    anterior->siguiente = new NodoPedido;
    anterior->siguiente->pedido = pedido;
    anterior->siguiente->siguiente = NULL;
  }

  void sacarPedido(Pedido pedido) {
    if (this->ultimo == NULL){
      this->primero = NULL;
      return;
    }

    NodoPedido* primero = this->primero;
    this->primero = this->primero->siguiente;
    delete primero;
    // if (this->primero == this->ultimo) {
    //   delete this->ultimo;
    //   this->primero->siguiente = NULL;
    //   this->ultimo = NULL;
    // }
  }
};
