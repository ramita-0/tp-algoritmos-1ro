#include <iostream>
#include <limits>
#include "./pedidos-actions.h"
#include "../../shared/data-structures/nodo-pedido.model.h"
#include "../../shared/utils/general-utils.h"
#include "../../shared/utils/business-utils.h"

bool pedidoEsValido(Repartidor[], int, Pedido);
void agregarPedidoACola(ListaColaPedidos*, Pedido);
void mostrarPedidos(ListaColaPedidos*);

void ingresarPedido(Repartidor repartidores[], int cantidadRepartidoresActuales, ListaColaPedidos*& listaColaPedidos) {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  Pedido newPedido;
  bool error = false;
  bool errorPaqueteValido = false;
  string input = "";

  do {
    if (errorPaqueteValido) {
      system("cls");
      cout << "No existen repartidores en la zona a repartir con el vehiculo precisado por el volumen del pedido." << endl;
      cout << "1 - Reingresar pedido" << endl;
      cout << "0 - Volver" << endl << endl;
      cin >> input;
      if (input == "0") return;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    
    do { // input zona loop
      system("cls");
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
      cout << "Ingrese el volumen del pedido en m3"<<endl<<endl;

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
    
    //TODO: PONER EN TRUE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if(!pedidoEsValido(repartidores, cantidadRepartidoresActuales, newPedido)) errorPaqueteValido = false;
    else errorPaqueteValido = false;
  
  } while(errorPaqueteValido);

  do { // input importe loop
    system("cls");
    if (error) cout << "Importe erroneo!"<<endl<<endl;
    cout << "Ingrese el importe del pedido"<<endl<<endl;

    getline(cin, input);
    float validInput;
    try {
      validInput= stof(input); // TODO: comprobar que este casteo anda 100% bien, no parece tener problemas de momento.
      newPedido.importe = validInput; 
      error = false;
    } catch(exception& e) {
      error = true;
    } 
  } while(error);

   do { // input codigoComercio loop
    system("cls");
    if (error) cout << "El codigo del comercio debe ser numerico!"<<endl<<endl;
    cout << "Ingrese el codigo del comercio que hizo la venta: "<<endl<<endl;
    getline(cin, input);
    if (!containsOnlyDigits(input) || cin.fail()) {
      error = true;
    }
    else {
      int validInput = stoi(input);
      newPedido.codigoComercio = validInput;
      error = false;
    }
  } while (error);

  system("cls");
  cout << "Ingrese el domicilio del destino del pedido"<<endl<<endl;

  getline(cin, input);
  newPedido.domicilio = input;

  // TODO: Guardar pedido en la cola, preguntar al usuario si quere seguir agregando pedidos o salir
  agregarPedidoACola(listaColaPedidos, newPedido); //TODO: Fix Segmentation fault
  mostrarPedidos(listaColaPedidos);
  cin >> input;
}

void asignarPedido() {
  //...
}
void mostrarPedidos(ListaColaPedidos* listaColaPedidos) {
  while(listaColaPedidos != NULL) {
    cout << "Zona: " << listaColaPedidos->zona << " Vehiculo: " << listaColaPedidos->tipoVehiculo << endl;
    NodoPedido* primerNodo = listaColaPedidos->colaPedidos->primero;

    cout << "Importe p/paquete: [ ";
    while(primerNodo != NULL) {
      cout << primerNodo->pedido.importe << ", ";
      primerNodo = primerNodo->siguiente;
    }
    cout << "]";
    listaColaPedidos = listaColaPedidos->siguienteCola;
  }
}

void agregarPedidoACola(ListaColaPedidos* listaColaPedidos, Pedido pedido) {
  if(listaColaPedidos == NULL) {
    listaColaPedidos->tipoVehiculo = Vehiculos(determinarVehiculoDelPedido(pedido));
    listaColaPedidos->zona = pedido.zonaDeEntrega;
    listaColaPedidos->siguienteCola = NULL;
    ColaPedidos* nuevaColaPedidos = new ColaPedidos;
    nuevaColaPedidos->primero->pedido = pedido;
    listaColaPedidos->colaPedidos = nuevaColaPedidos;
    return;
  }

  ListaColaPedidos* actual = listaColaPedidos;
  ListaColaPedidos* anterior = actual;

  while(actual != NULL) {
    if (actual->zona == pedido.zonaDeEntrega && actual->tipoVehiculo == Vehiculos(determinarVehiculoDelPedido(pedido))) {
      // 1 nodo
      if (actual->colaPedidos->ultimo == NULL) {
        actual->colaPedidos->ultimo->pedido = pedido;
        actual->colaPedidos->primero->siguiente = actual->colaPedidos->ultimo;
        return;
      }
      // mas de 1 nodo
      else {
        NodoPedido* nuevoPedido = new NodoPedido;
        nuevoPedido->pedido = pedido;
        nuevoPedido->siguiente = NULL;
        actual->colaPedidos->ultimo->siguiente = nuevoPedido;
        return;
      }
    }
    else {
      anterior = actual;
      actual = actual->siguienteCola;
    }
  }
  //llegue al final, tengo que agregar una nueva cola con su zona y tipo vehiculo
  if (actual == NULL) {
    ListaColaPedidos* nuevaListaColaPedidos = new ListaColaPedidos;
    nuevaListaColaPedidos->tipoVehiculo =  Vehiculos(determinarVehiculoDelPedido(pedido));
    nuevaListaColaPedidos->zona = pedido.zonaDeEntrega;
    nuevaListaColaPedidos->siguienteCola = NULL;

    ColaPedidos* nuevaColaPedidos = new ColaPedidos;
    nuevaColaPedidos->primero->pedido = pedido;
    nuevaListaColaPedidos->colaPedidos = nuevaColaPedidos;
    anterior->siguienteCola = nuevaListaColaPedidos;

    return;
  }
}

bool pedidoEsValido(Repartidor repartidores[], int cantidadRepartidoresActuales, Pedido pedido) {
  int vehiculoPedido = determinarVehiculoDelPedido(pedido);
  for(int i = 0; i < cantidadRepartidoresActuales; i++) {
    if (repartidores[i].zona == pedido.zonaDeEntrega && repartidores[i].vehiculo.tipo == Vehiculos(vehiculoPedido)) { // TODO: Fix as when there are >1 repartidores in the array it does not validate correctly.
      // Existe un repartidor en la zona del paquete, con el vehiculo necesitado determinado por el volumen del pedido, 
      // que esta disponible para realizar la entrega.
      return true;
    }
    return false;
  }
}
