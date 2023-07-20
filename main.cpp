#include <iostream>
#include <stdlib.h>
#include "./shared/utils/file-utils.h"
#include "./shared/model/repartidor.model.h"
#include "./entities/repartidores/repartidores-controller.h"
using namespace std;

void printMainMenu(bool error);

int main() {
  unsigned userInput = 0;
  bool error = false;

  do {
    printMainMenu(error);
    cin >> userInput; // TODO: Si el user mete un string, se rompe, handlear este caso y poner el error = true
    switch (userInput) {
      case 1:
        error = false;
        repartidoresMain();
        break;
      case 2:
        error = false;
        // TODO: informesMain();
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