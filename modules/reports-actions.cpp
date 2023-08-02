#include <iostream>
#include "../shared/model/repartidor.model.h"
#include "./reports-actions.h"
#include "../shared/utils/general-utils.h"
using namespace std;

void repartidoresPorZona(int matriz[4][14], int size, int vectorSuma[]);
int maximoZona(int vectorSuma[]);
void informeDeZonas(int vectorSuma[], int maximo);

void mostrarTransportesNoDisponibles(int arr[]);
void sumatoriaVehiculosTotaleseEntreZonas (int arr[], int matriz[4][14]);
string retornarTipoVehiculo(int numero);

void informarZonasConMayorCantidadDeRepartidores (Repartidor repartidores[], int cantidadRepartidoresActuales)
{
  int vectorSuma[14]={0};
  int M[4][14]={0};
  int maximo;
  generarSumatoriaVehiculosZona(M,repartidores,cantidadRepartidoresActuales);
  repartidoresPorZona(M,cantidadRepartidoresActuales,vectorSuma);
  maximo=maximoZona(vectorSuma);
  informeDeZonas(vectorSuma,maximo);
}

void repartidoresPorZona(int matriz[4][14], int size, int vectorSuma[])
{
  int suma=0;
  for (int i=0; i<14; i++) {
    for (int j=0; j<4; j++) {
      suma+=matriz[j][i];
    }
    vectorSuma[i]=suma;
    suma=0;
  }
}

int maximoZona(int vectorSuma[])
{
  int maximo;
  for(int i=0; i<14; i++) {
    if(i==0 || vectorSuma[i]>maximo) maximo=vectorSuma[i];
  }
  return maximo;
}

void informeDeZonas(int vectorSuma[], int m)
{
  system("cls");
  if (m == 0) cout << "No hay repartidores cargados en el sistema";
  else {
    cout<<"Zona/s con mas repartidores (sin diferenciar el transporte): ";
    for(int i=0; i<14; i++) {
      if(vectorSuma[i] == m) cout<<i+1<<" ";
    }
  }
  cout<<endl<<endl<<"Ingrese cualquier numero para volver"<<endl<<endl;
  string variable;
  cin>>variable;
}

void informarTransportesNoDisponibles(Repartidor repartidores[], int cantidadRepartidoresActuales) {
  int mat[4][14] = {0};
  generarSumatoriaVehiculosZona(mat, repartidores, cantidadRepartidoresActuales);

  int sumatoriaVehiculos[4] = {0};
  sumatoriaVehiculosTotaleseEntreZonas(sumatoriaVehiculos, mat);
  mostrarTransportesNoDisponibles(sumatoriaVehiculos);
}

void sumatoriaVehiculosTotaleseEntreZonas (int arr[], int matriz[4][14])
{
  for (int i = 0; i < 4; i ++) {
    int suma = 0;
    for (int j = 0; j < 14; j++) {
      suma += matriz[i][j];
    }
    arr[i] = suma;
  }
}

string retornarTipoVehiculo(int numero) {
  switch (numero) {
    case 0:
      return "Auto";
    case 1:
      return "Moto";
    case 2:
      return "Camion";
    case 3:
      return "Camioneta";
  }
}

void mostrarTransportesNoDisponibles(int arr[])
{
  system("cls");
  bool transportesNoDisponibles = false;

  for (int i = 0; i < 4; i++) {
    if (arr[i] == 0) {
      transportesNoDisponibles = true;
      break;
    }
  }

  if (transportesNoDisponibles) {
    cout << "Los vehiculos no disponibles son: ";
    for (int i = 0; i < 4; i++) {
      if (arr[i] == 0) cout << retornarTipoVehiculo(i)<<" ";
    }
  }
  else cout<< "Todos los tipos de vehiculos tienen repartidores.";

  cout<<endl<<endl<<"Ingrese cualquier numero para volver"<<endl<<endl;
  string variable;
  cin>>variable;
}

void transportesPorZona(Repartidor repartidores[], int cantidadRepartidoresActuales )
{
    int M[4][14]={0};
    generarSumatoriaVehiculosZona(M,repartidores,cantidadRepartidoresActuales);
    for(int i=0; i<4; i++)
    {
        if(i==0) cout << "Zona:      01  02  03  04  05  06  07  08  09  10  11  12  13  14"<<endl;
        string tipo = retornarTipoVehiculo(i);
        cout << tipo;
        if(i==0 || i==1) cout << ":      ";
        if(i==2) cout << ":    ";  
        if(i==3) cout << ": ";
        for(int j=0; j<14; j++)
        {
            if(M[i][j]<10) cout << "0"<< M[i][j]<<"  ";
            if(M[i][j]>=10) cout << M[i][j]<<"  ";
        }
        cout<<endl;
    }
    string out;
    cin>>out;
}

