#include <iostream>
#include <stdlib.h>
#include "repartidores-controller.h"
using namespace std;

void printRepartidoresMenu(bool error);

void repartidoresMain() {
  unsigned userInput = 0;
  bool error = false;

  do {
    printRepartidoresMenu(error);
    cin >> userInput; // TODO: Si el user mete un string, se rompe, handlear este caso y poner el error = true
    switch (userInput) {
      case 1:
        error = false;
        // TODO: Funcion de alta definida en repartidores-actions.cpp
        break;
      case 0:
        error = false;
        return;
      default:
        error = true;
    }
  } while(userInput != 0);
}

void printRepartidoresMenu(bool error) {
  system("cls");
  if (error) cout<<"Opcion incorrecta!"<<endl<<endl;
  cout<<"1 - Alta repartidor"<<endl;
  cout<<"0 - Volver"<<endl<<endl;
}
