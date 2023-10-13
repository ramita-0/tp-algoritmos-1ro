#pragma once
#include <string>
using namespace std;

struct Pedido {
    string domicilio;
    int zonaDeEntrega; // 1 a 14, como en el repartidor
    float volumen;
    float importe;
    int codigo; // TODO: Ver que tipo de dato usamos para el codigo!
};