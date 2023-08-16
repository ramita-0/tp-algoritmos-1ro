#include <iostream>
#include <stdlib.h>
#include <limits>
#include <regex>
#include<algorithm>
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
        if (error) cout << "La zona ingresada no existe!"<<endl<<endl;
        cout << "Ingrese la zona del nuevo repartidor (1-14): "<<endl<<endl;
        cin >> intUserInput;
        if (cin.fail()) {
          error = true;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          intUserInput = 999;
        }

        if (intUserInput >= 1 && intUserInput <= 14) {
          newRepartidor.zona = intUserInput - 1;
          error = false;
        }
        else error = true;
      } while (error);

      do { // input vehiculo loop
        system("cls");
        if (error) cout << "Opcion incorrecta!"<<endl<<endl;
        cout << "Ingrese el tipo de vehiculo: "<<endl<<endl;
        cout << "1 - Auto"<<endl;
        cout << "2 - Moto"<<endl;
        cout << "3 - Camion"<<endl;
        cout << "4 - Camioneta"<<endl<<endl;
        cin >> intUserInput;
        if (cin.fail()) {
          error = true;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          intUserInput = 999;
        }

        if (intUserInput >= 1 && intUserInput <= 4) {
          error = false;
          newRepartidor.vehiculo.tipo = Vehiculos(intUserInput - 1);
        }
        else error = true;
      } while(error);

      if (zonasVehiculosSum[newRepartidor.vehiculo.tipo][newRepartidor.zona] + 1 > 20) {
        maxRepZonaVehiculoError = true;
      }
      else {
        maxRepZonaVehiculoError = false;
        break;
      }
    }

    do { // input dni loop
      system("cls");
      if (error) cout << "DNI Erroneo!"<<endl<<endl;
      cout << "Ingrese el DNI del repartidor"<<endl<<endl;

      cin >> intUserInput;
      if (cin.fail()) {
        error = true;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        intUserInput = 999;
      }
      else {
        newRepartidor.dni = intUserInput; 
        error = false;
      } 
    } while(error);

    do { //input patente loop
      system("cls");
      if (error) cout << "Patente erronea!"<<endl<<endl;
      cout << "Ingrese la patente del vehiculo"<<endl<<endl;
      cin >> stringUserInput;
      if (regex_match(stringUserInput, regex("^[A-Za-zñÑ]{3}\\s?\\d{3}$|^[A-Za-zñÑ]{2}\\s?\\d{3}\\s?[A-Za-zñÑ]{2}$"))) {
        error = false;
        newRepartidor.vehiculo.patente = stringUserInput;
      }
      else error = true;
    } while (error);

    system("cls");
    cout << "Ingrese el nombre del repartidor"<<endl<<endl;

    cin >> stringUserInput;
    newRepartidor.nombre = stringUserInput;

    system("cls");
    cout << "Ingrese el apellido del repartidor"<<endl<<endl;

    cin >> stringUserInput;
    newRepartidor.apellido = stringUserInput;

    repartidores[cantidadRepartidoresActuales] = newRepartidor;
    zonasVehiculosSum[newRepartidor.vehiculo.tipo][newRepartidor.zona] ++;
    cantidadRepartidoresActuales ++;
    repartidoresRestantes --;

    do {
      // TODO: refactor this part to match the do... while with switch case used across the programm
      system("cls");
      if (error) cout << "Opcion incorrecta!"<<endl<<endl;
      cout << "Continuar ingresando repartidores?"<<endl;
      cout << "1 - Si"<<endl;
      cout << "0 - Guardar y volver"<<endl<<endl;
      cin >> intUserInput;
      if (cin.fail()) {
        error = true;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        intUserInput = 999;
      }

      if (intUserInput == 1) {
        error = false;
        break;
      }
      if (intUserInput == 0) {
        error = false;
        writeToFiles(repartidores, cantidadRepartidoresActuales);
        return;
      }
      error = true;
    } while(true);
  }
  return;
}
