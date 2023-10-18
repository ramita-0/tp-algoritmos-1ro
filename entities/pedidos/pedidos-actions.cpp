#include <iostream>
#include <limits>
#include "./pedidos-actions.h"
#include "../../shared/data-structures/nodo-pedido.model.h"
#include "../../shared/utils/general-utils.h"
#include "../../shared/utils/business-utils.h"

bool pedidoEsValido(Repartidor[], int, Pedido);

void ingresarPedido(Repartidor repartidores[], int cantidadRepartidoresActuales, ListaColaPedidos*& listaColaPedidos) {
  system("cls");
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  Pedido newPedido;
  bool error = false;
  bool errorPaqueteValido = false;
  string input = "";

  do {
    if (errorPaqueteValido) {
      cout << "No existen repartidores en la zona a repartir, y con el vehiculo precisado por el volumen." << endl;
      cout << "Por favor, ingrese otros datos" << endl << endl; // TODO: salir de la funcion.
    }

    do { // input zona loop
      if (error) cout << "La zona ingresada no existe!"<<endl<<endl;
      cout << "Ingrese la zona del nuevo pedido (1-14): "<<endl<<endl;
      getline(cin, input);
      if (!containsOnlyDigits(input) || cin.fail()) {
        error = true;
      }
      else {
        int validInput = stoi(input);

        if (zonaEsValida(validInput)) {
          newPedido.zonaDeEntrega = validInput - 1;
          error = false;
        }
        else error = true;
      }
    } while (error);

    do { // input volumen loop
      system("cls");
      if (error) cout << "Volumen erroneo!"<<endl<<endl;
      cout << "Ingrese el volumen del pedido"<<endl<<endl;

      getline(cin, input);
      float validInput;
      try {
        validInput= stof(input); // TODO: comprobar que este casteo anda 100% bien, no parece tener problemas de momento.
        newPedido.volumen = validInput; 
        error = false;
      } catch(exception& e) {
        error = true;
      } 
    } while(error);

    if(!pedidoEsValido(repartidores, cantidadRepartidoresActuales, newPedido)) errorPaqueteValido = true;
    else errorPaqueteValido = false;
  } while(errorPaqueteValido);
}

void asignarPedido() {
  //...
}

void agregarPedidoACola(ListaColaPedidos* listaColaPedidos, Pedido pedido) {

}

bool pedidoEsValido(Repartidor repartidores[], int cantidadRepartidoresActuales, Pedido pedido) {
  int vehiculoPedido = determinarVehiculoDelPedido(pedido);
  for(int i = 0; i < cantidadRepartidoresActuales; i++) {
    if (repartidores[i].zona == pedido.zonaDeEntrega && repartidores[i].vehiculo.tipo == Vehiculos(vehiculoPedido)) {
      // Existe un repartidor en la zona del paquete, con el vehiculo necesitado determinado por el volumen del pedido, 
      // que esta disponible para realizar la entrega.
      return true;
    }
    return false;
  }
}
