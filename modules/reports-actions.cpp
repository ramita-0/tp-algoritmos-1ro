#include <iostream>
#include "../shared/model/repartidor.model.h"
#include "./reports-actions.h"
#include "../shared/utils/general-utils.h"
using namespace std;

void repartidoresPorZona(int matriz[][14], int size, int vectorSuma[]);
void maximoZona(int vectorSuma[], int zonas[], int &j);
void informeDeZonas(int vectorSuma[], int zonas[], int tamZonas);

void Informe3 (Repartidor repartidores[], int cantidadRepartidoresActuales)
{
    int vectorSuma[14];
    int zonas[14];
    int tamZonas;
    int M[5][14];
    generarSumatoriaVehiculosZona(M,repartidores,cantidadRepartidoresActuales);
    repartidoresPorZona(M,cantidadRepartidoresActuales,vectorSuma);
    maximoZona(vectorSuma,zonas,tamZonas);
    informeDeZonas(vectorSuma,zonas,tamZonas);
}

void repartidoresPorZona(int matriz[][14], int size, int vectorSuma[])
{
    int suma=0;
    for (int i=0; i<14; i++){
        for (int j=0; j<5; j++){
            suma+=matriz[j][i];
        }
        vectorSuma[i]=suma;
        suma=0;
    }
}

void maximoZona(int vectorSuma[], int zonas[], int &j)
{
    int maximo;
    for(int i=0;i<14;i++)
    {
        if(i==0 || vectorSuma[i]>maximo)
        {
            maximo=vectorSuma[i];
            j=0;
            zonas[j]=i;
            j++;
        }
        else
        {
            if(vectorSuma[i]==maximo)
            {
                zonas[j]=i;
                j++;
            }
        }
    }
}

void informeDeZonas(int vectorSuma[], int zonas[], int tamZonas)
{
    int posicion;
    cout<<"Zona/s con mas repartidores (sin diferenciar el transporte):"<<endl;
    for(int i=0; i<tamZonas; i++)
    {
        zonas[i]=posicion;
        cout<<vectorSuma[posicion]-1<<endl;
    }
}