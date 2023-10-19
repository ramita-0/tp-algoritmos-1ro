#include <iostream>
#include <stdlib.h>
#include <limits>
#include "./shared/utils/file-utils.h"
#include "./shared/model/repartidor.model.h"
#include "./entities/repartidores/repartidores-controller.h"
#include "./entities/pedidos/pedidos-controller.h"
#include "./modules/reports-controller.h"
#include "./shared/data-structures/lista-cola-pedidos.h"
using namespace std;

void printMainMenu(bool error);

int main() {
  int userInput = 999;
  bool error = false;

  // Estado de la app
  Repartidor repartidores[1120] = {};
  int cantidadRepartidoresActuales = 0;

  ListaColaPedidos* listaColaPedidos = NULL; // TODO: chequear esta inicializacion

  do {
    printMainMenu(error);
    cin >> userInput;
    if (cin.fail()) {
      error = true;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      userInput = 999;
    }
    switch (userInput) {
      case 1:
        error = false;
        repartidoresMain(repartidores, cantidadRepartidoresActuales);
        break;
      case 2:
        error = false;
        pedidosMain(repartidores, cantidadRepartidoresActuales, listaColaPedidos);
        break;
      case 3:
        error = false;
        informesMain(repartidores, cantidadRepartidoresActuales);
        break;
      case 0:
        return 0;
      default:
        error = true;
    }
  } while(true);
}

void printMainMenu(bool error) {
  system("cls");
  if (error) cout<<"Opcion incorrecta!"<<endl<<endl;
  cout<<"1 - Gestionar Repartidores"<<endl;
  cout<<"2 - Gestionar Pedidos"<<endl;
  cout<<"3 - Informes"<<endl;
  cout<<"0 - Salir"<<endl<<endl;
}