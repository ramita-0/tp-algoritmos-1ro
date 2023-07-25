#pragma once
#include <string>
#include "./vehiculo.model.h"
using namespace std;
struct Repartidor {
  // string zona ?
  string nombre;
  string apellido;
  int dni;
  Vehiculo vehiculo;
};