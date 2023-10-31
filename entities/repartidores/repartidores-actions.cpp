#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include <regex>
#include <algorithm>
#include <cctype>
#include "repartidores-actions.h"
#include "../../shared/model/repartidor.model.h"
#include "../../shared/utils/file-utils.h"
#include "../../shared/utils/general-utils.h"
#include "../../shared/utils/business-utils.h"
using namespace std;

void altaRepartidores(Repartidor repartidores[], int& cantidadRepartidoresActuales) {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  int repartidoresRestantes = 1120 - cantidadRepartidoresActuales;

  int zonasVehiculosSum[4][14] = {0};
  generarSumatoriaVehiculosZona(zonasVehiculosSum, repartidores, cantidadRepartidoresActuales);

  string input = "";

  while (repartidoresRestantes != 0) { // main new repartidor loop

    Repartidor newRepartidor;
    newRepartidor.listaPedidosEntregados = NULL; // TODO: Justificar
    bool error = false;
    bool maxRepZonaVehiculoError = false;
    
    while (true) {

      do { // input zona loop
        system("cls");
        if (maxRepZonaVehiculoError) cout << "El vehiculo y zona seleccionados, cuentan con el maximo de repartidores posibles, por favor elija otra combinacion"<<endl<<endl;
        if (error) cout << "La zona ingresada no existe!"<<endl<<endl;
        cout << "Ingrese la zona del nuevo repartidor (1-14): "<<endl<<endl;
        getline(cin, input);
        if (!containsOnlyDigits(input) || cin.fail()) {
          error = true;
        }
        else {
          int validInput = stoi(input);

          if (zonaEsValida(validInput)) {
            newRepartidor.zona = validInput - 1;
            error = false;
          }
          else error = true;
        }
      } while (error);

      do { // input vehiculo loop
        system("cls");
        if (error) cout << "Opcion incorrecta!"<<endl<<endl;
        cout << "Ingrese el tipo de vehiculo: "<<endl<<endl;
        cout << "1 - Auto"<<endl;
        cout << "2 - Moto"<<endl;
        cout << "3 - Camion"<<endl;
        cout << "4 - Camioneta"<<endl<<endl;
        getline(cin, input);
        if (!containsOnlyDigits(input) || cin.fail()) {
          error = true;
        }
        else {
          int validInput = stoi(input);

          if (vehiculoEsValido(validInput)) {
            newRepartidor.vehiculo.tipo = Vehiculos(validInput - 1);
            error = false;
          }
          else error = true;
        }
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

      getline(cin, input);
      if (!containsOnlyDigits(input) || cin.fail()) {
        error = true;
      }
      else {
        error = false;
        int validInput = stoi(input);
        newRepartidor.dni = validInput; 
      } 
    } while(error);

    do { //input patente loop
      system("cls");
      if (error) cout << "Patente erronea!"<<endl<<endl;
      cout << "Ingrese la patente del vehiculo"<<endl<<endl;
      getline(cin, input);
      // TODO: sanitize input (to uppercase, remove whitespaces)
      if (regex_match(input, regex("^[A-Za-zñÑ]{3}\\s?\\d{3}$|^[A-Za-zñÑ]{2}\\s?\\d{3}\\s?[A-Za-zñÑ]{2}$"))) {
        error = false;
        newRepartidor.vehiculo.patente = input;
      }
      else error = true;
    } while (error);


    // TODO: loop so it cant enter empty value
    system("cls");
    cout << "Ingrese el nombre del repartidor"<<endl<<endl;

    getline(cin, input);
    newRepartidor.nombre = input;

    // TODO: loop so it cant enter empty value
    system("cls");
    cout << "Ingrese el apellido del repartidor"<<endl<<endl;

    getline(cin, input);
    newRepartidor.apellido = input;

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
      getline(cin, input);
      if (!containsOnlyDigits(input) || cin.fail()) {
        error = true;
      }
      else {
        int validInput = stoi(input);

        if (validInput == 1) {
          error = false;
          break;
        }
        if (validInput == 0) {
          error = false;
          writeToFiles(repartidores, cantidadRepartidoresActuales);
          return;
        }
        error = true;
      }
    } while(true);
  }
  return;
}

