#include <iostream>
#include <stdlib.h>
#include "./shared/utils/file-utils.h"
#include "./shared/model/repartidor.model.h"
#include "./entities/repartidores/repartidores-controller.h"
#include "./modules/reports-controller.h"
using namespace std;

void printMainMenu(bool error);

int main() {
  unsigned userInput = 0;
  bool error = false;

  Repartidor repartidores[1120] = {};
  int cantidadRepartidoresActuales = 0;

  do {
    printMainMenu(error);
    cin >> userInput; // TODO: Si el user mete un string, se rompe, handlear este caso y poner el error = true
    switch (userInput) {
      case 1:
        error = false;
        repartidoresMain(repartidores, cantidadRepartidoresActuales);
        break;
      case 2:
        error = false;
        informesMain(repartidores, cantidadRepartidoresActuales);
        break;
      case 0:
        break;
      default:
        error = true;
    }
  } while(userInput != 0);

  return 0;
}

void printMainMenu(bool error) {
  system("cls");
  if (error) cout<<"Opcion incorrecta!"<<endl<<endl;
  cout<<"1 - Gestionar Repartidores"<<endl;
  cout<<"2 - Informes"<<endl;
  cout<<"0 - Salir"<<endl<<endl;
}