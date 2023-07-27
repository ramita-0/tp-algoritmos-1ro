#include <iostream>
#include <stdlib.h>
#include "./repartidores-actions.h"
#include "../../shared/model/repartidor.model.h"

void printMatrix(int mat[5][14]); // function made for testing purposes

void altaRepartidores(Repartidor repartidores[], int& cantidadRepartidoresActuales) {
  int repartidoresRestantes = 1120 - cantidadRepartidoresActuales;

  int zonasVehiculosSum[5][14] = {0};
  for (int i = 0; i < cantidadRepartidoresActuales; i ++){
    int zonaRepartidorActual = repartidores[i].zona;
    int vehiculoRepartidorActual = repartidores[i].vehiculo.tipo;

    zonasVehiculosSum[vehiculoRepartidorActual][zonaRepartidorActual - 1] ++;
  }
  
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
        cout << "Ingrese la zona del nuevo repartidor (1-14): "<<endl;
        cin >> intUserInput; // TODO: validar que no se meta un string.
      
        if (intUserInput >= 1 && intUserInput <= 14) {
          newRepartidor.zona = intUserInput;
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
          newRepartidor.vehiculo.tipo = Vehiculos(intUserInput);
          error = false;
          break;
        }
        else error = true;
      } while(intUserInput <= 1 || intUserInput >= 4);

      if (zonasVehiculosSum[newRepartidor.vehiculo.tipo][newRepartidor.zona - 1] + 1 > 20) {
        maxRepZonaVehiculoError = true;
      }
      else break;
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

    
    // TODO: escribir en archivo writeToFiles() y que dentro de esa fucnion, este el sort!
    repartidores[cantidadRepartidoresActuales] = newRepartidor;
    zonasVehiculosSum[newRepartidor.vehiculo.tipo][newRepartidor.zona - 1] ++;
    cantidadRepartidoresActuales ++;
    repartidoresRestantes --;
  }
  return;
}

// function made for testing purposes.
void printMatrix(int mat[5][14]) {
  for (int i = 0; i < 5; i ++) {
    for (int j = 0; j < 14; j ++) {
      cout << mat[i][j] << " ";
    }
    cout<<endl;
  }
}