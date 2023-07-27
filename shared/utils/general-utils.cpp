#include <iostream>
#include "../model/repartidor.model.h"

void ordenamientoDeRepartidores(Repartidor repartidores[], int size)
{
    int i=0;
    Repartidor aux;
    bool cambio;
    do
    {
        cambio=false;
        for(int j=0;j<size-i;j++)
        {
            if(repartidores[j].dni>repartidores[j+1].dni)
            {
                aux=repartidores[j];
                repartidores[j]=repartidores[j+1];
                repartidores[j+1]=aux;
                cambio=true;
            }
        }
        i++;
    }while(i<size && cambio);
}