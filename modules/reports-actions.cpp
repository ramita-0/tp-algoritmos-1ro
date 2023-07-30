#include <iostream>
#include "../shared/model/repartidor.model.h"
#include "./reports-actions.h"
#include "../shared/utils/general-utils.h"
using namespace std;

void repartidoresPorZona(int matriz[][14], int size, int vectorSuma[]);
int maximoZona(int vectorSuma[]);
void informeDeZonas(int vectorSuma[], int maximo);

void informarZonasConMayorCantidadDeRepartidores (Repartidor repartidores[], int cantidadRepartidoresActuales)
{
  int vectorSuma[14]={0};
  int M[5][14]={0};
  int maximo;
  generarSumatoriaVehiculosZona(M,repartidores,cantidadRepartidoresActuales);
  repartidoresPorZona(M,cantidadRepartidoresActuales,vectorSuma);
  maximo=maximoZona(vectorSuma);
  informeDeZonas(vectorSuma,maximo);
}

void repartidoresPorZona(int matriz[][14], int size, int vectorSuma[])
{
  int suma=0;
  for (int i=0; i<14; i++) {
    for (int j=0; j<5; j++) {
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