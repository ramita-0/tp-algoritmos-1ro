#include <iostream>
#include <stdlib.h>
#include <limits>
#include "repartidores-controller.h"
#include "../../shared/model/repartidor.model.h"
#include "./repartidores-actions.h"
using namespace std;

void printRepartidoresMenu(bool error);

void repartidoresMain(Repartidor repartidores[], int& cantidadRepartidoresActuales) {
  int userInput = 999;
  bool error = false;

  do {
    printRepartidoresMenu(error);
    if (cantidadRepartidoresActuales == 1120) cout << "Aviso: Maximo de repartidores alcanzado!"<<endl<<endl;
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
        altaRepartidores(repartidores, cantidadRepartidoresActuales);
        break;
      case 0:
        return;
      default:
        error = true;
    }
  } while(true);
}

void printRepartidoresMenu(bool error) {
  system("cls");
  if (error) cout<<"Opcion incorrecta!"<<endl<<endl;
  cout<<"1 - Alta repartidor"<<endl;
  cout<<"0 - Volver"<<endl<<endl;
}
