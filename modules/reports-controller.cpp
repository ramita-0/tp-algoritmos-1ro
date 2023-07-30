#include "../shared/model/repartidor.model.h"
#include "./reports-controller.h"
#include "./reports-actions.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void printInformesMenu(bool);

void informesMain(Repartidor repartidores[], int cantidadRepartidoresActuales)
{
    unsigned userInput = 0;
    bool error = false;
    do {
        printInformesMenu(error);
        cin >> userInput; // TODO: Si el user mete un string, se rompe, handlear este caso y poner el error = true
        switch (userInput) {
        case 1:
            error = false;
            //TODO: Generar informe caso 1
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
        
    } while(userInput != 0);
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