#include <iostream>
#include <limits>
#include "./pedidos-controller.h"
#include "./pedidos-actions.h"
#include "../../shared/data-structures/cola-pedidos.h"
#include "../../shared/data-structures/nodo-arbol.h"
using namespace std;

void printMenuPedidos(bool error);

void pedidosMain(Repartidor repartidores[], int cantidadRepartidoresActuales, ListaColaPedidos*& listaColaPedidos, NodoArbol*& raiz) {
  bool error = false;
  int userInput = 999;

  do {
    printMenuPedidos(error);
    cin >> userInput;
    if (cin.fail()) {
      error = true;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      userInput = 999;
    }
    switch(userInput) {
      case 1:
        error = false;
        ingresarPedido(repartidores, cantidadRepartidoresActuales, listaColaPedidos);
        break;
      case 2:
        error = false;
        asignarPedido(repartidores, cantidadRepartidoresActuales, listaColaPedidos, raiz);
        break;
      case 0:
        return;
      default:
        error = true;    
      }
  } while(true);
}

void printMenuPedidos(bool error)
{
  system("cls");
  if (error) cout<<"Opcion incorrecta!"<<endl<<endl;
  cout<<"1 - Ingresar un pedido"<<endl;
  cout<<"2 - Asignar pedido a un repartidor"<<endl;
  cout<<"0 - Volver"<<endl<<endl; 
}
