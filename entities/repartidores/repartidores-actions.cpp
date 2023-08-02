#include <iostream>
#include <stdlib.h>
#include "./repartidores-actions.h"
#include "../../shared/model/repartidor.model.h"
#include "../../shared/utils/file-utils.h"
#include "../../shared/utils/general-utils.h"
using namespace std;

void altaRepartidores(Repartidor repartidores[], int& cantidadRepartidoresActuales) {
  int repartidoresRestantes = 1120 - cantidadRepartidoresActuales;

  int zonasVehiculosSum[4][14] = {0};
  generarSumatoriaVehiculosZona(zonasVehiculosSum, repartidores, cantidadRepartidoresActuales);

  int intUserInput;
  string stringUserInput;

  while (repartidoresRestantes != 0) { // main new repartidor loop

    Repartidor newRepartidor;
    bool error = false;
    bool maxRepZonaVehiculoError = false;

    while (true) {

      do { // input zona loop
        system("cls");
        if (maxRepZonaVehiculoError) cout << "El vehiculo y zona seleccionados, cuentan con el maximo de repartidores posibles, por favor elija otra combinacion"<<endl<<endl;
        if (error) cout << "Opcion incorrecta!"<<endl<<endl;
        cout << "Ingrese la zona del nuevo repartidor (1-14): "<<endl<<endl;
        cin >> intUserInput; // TODO: validar que no se meta un string.
      
        if (intUserInput >= 1 && intUserInput <= 14) {
          newRepartidor.zona = intUserInput - 1;
          error = false;
          break;
        }
        else error = true;
      } while (intUserInput <= 1 || intUserInput >= 14);

      do { // input vehiculo loop
        system("cls");
        if (error) cout << "Opcion incorrecta!"<<endl<<endl;
        cout << "Ingrese el tipo de vehiculo: "<<endl<<endl;
        cout << "1 - Auto"<<endl;
        cout << "2 - Moto"<<endl;
        cout << "3 - Camion"<<endl;
        cout << "4 - Camioneta"<<endl<<endl;
        cin >> intUserInput; // TODO: validar que no se meta un string.

        if (intUserInput >= 1 && intUserInput <= 4) {
          newRepartidor.vehiculo.tipo = Vehiculos(intUserInput - 1);
          error = false;
          break;
        }
        else error = true;
      } while(intUserInput <= 1 || intUserInput >= 4);

      if (zonasVehiculosSum[newRepartidor.vehiculo.tipo][newRepartidor.zona] + 1 > 20) {
        maxRepZonaVehiculoError = true;
      }
      else {
        maxRepZonaVehiculoError = false;
        break;
      }
    }

    system("cls");
    cout << "Ingrese la patente del vehiculo"<<endl<<endl;
    cin >> stringUserInput;
    newRepartidor.vehiculo.patente = stringUserInput;

    system("cls");
    cout << "Ingrese el nombre del repartidor"<<endl<<endl;

    cin >> stringUserInput;
    newRepartidor.nombre = stringUserInput;

    system("cls");
    cout << "Ingrese el apellido del repartidor"<<endl<<endl;

    cin >> stringUserInput;
    newRepartidor.apellido = stringUserInput;

    system("cls");
    cout << "Ingrese el DNI del repartidor"<<endl<<endl;

    cin >> intUserInput; // TODO: validar que no se meta un string
    newRepartidor.dni = intUserInput; 

    repartidores[cantidadRepartidoresActuales] = newRepartidor;
    zonasVehiculosSum[newRepartidor.vehiculo.tipo][newRepartidor.zona] ++;
    cantidadRepartidoresActuales ++;
    repartidoresRestantes --;

    do {
      system("cls");
      if (error) cout << "Opcion incorrecta!"<<endl<<endl;
      cout << "Continuar ingresando repartidores?"<<endl;
      cout << "1 - Si"<<endl;
      cout << "0 - Guardar y volver"<<endl<<endl;
      cin >> intUserInput; // TODO: Validar input que no sea un string

      if (intUserInput == 1) {
        error = false;
        break;
      }
      if (intUserInput == 0) {
        error = false;
        writeToFiles(repartidores, cantidadRepartidoresActuales); // TODO: Testear!
        return;
      }
      error = true;
    } while(true);
  }
  return;
}
