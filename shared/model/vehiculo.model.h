#pragma once
#include <string>
#include "../enum/vehiculos.enum.h"
using namespace std;

struct Vehiculo {
  Vehiculos tipo;
  string patente;
};