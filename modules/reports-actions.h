#pragma once
#include "../shared/model/repartidor.model.h"

void informarCantidadTransportesPorZona(Repartidor repartidores[], int cantidadRepartidoresActuales);

void informarTransportesNoDisponibles(Repartidor[], int);

void informarZonasConMayorCantidadDeRepartidores (Repartidor[], int);

void informarEntregasRealizadasPorRepartidores (Repartidor[], int);
