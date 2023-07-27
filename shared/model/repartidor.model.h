#pragma once
#include <string>
#include "./vehiculo.model.h"
using namespace std;
struct Repartidor {
  string nombre;
  string apellido;
  int dni;
  int zona;
  Vehiculo vehiculo;
};