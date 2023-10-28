#pragma once
#include <string>
using namespace std;

struct Pedido {
    string domicilio;
    int zonaDeEntrega; // 1 a 14
    float volumen;
    float importe;
    int codigoComercio;
};