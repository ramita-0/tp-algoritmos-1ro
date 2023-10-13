#include <iostream>
#include <stdlib.h>
#include <limits>
#include "reports-controller.h"
#include "reports-actions.h"
#include "../shared/model/repartidor.model.h"
using namespace std;

void printInformesMenu(bool);

void informesMain(Repartidor repartidores[], int cantidadRepartidoresActuales) {
  int userInput = 999;
  bool error = false;

  do {
    printInformesMenu(error);
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
      informarCantidadTransportesPorZona(repartidores,cantidadRepartidoresActuales);
      break;
    case 2:
      error = false;
      informarTransportesNoDisponibles(repartidores, cantidadRepartidoresActuales);
      break;
    case 3:
      error = false;
      informarZonasConMayorCantidadDeRepartidores(repartidores, cantidadRepartidoresActuales);
      break;
    case 0:
      return;
    default:
      error = true;
    }
  } while(true);
}


  void printInformesMenu(bool error)
  {
  system("cls");
  if (error) cout<<"Opcion incorrecta!"<<endl<<endl;
  cout<<"1 - Informar cantidad de repartidores por medio de transporte por zona"<<endl;
  cout<<"2 - Informar medios de transportes no existentes (de todas las zonas)"<<endl;
  cout<<"3 - Informar zonas con mas repartidores inscriptos"<<endl;
  cout<<"0 - Volver"<<endl<<endl;
  }