#include <iostream>
#include <limits>
#include "./pedidos-actions.h"
#include "../../shared/data-structures/lista-cola-pedidos.h"
#include "../../shared/model/repartidor.model.h"
#include "../../shared/utils/file-utils.h"
#include "../../shared/utils/general-utils.h"
#include "../../shared/utils/business-utils.h"
#include "../../shared/data-structures/nodo-arbol.h"
using namespace std;

bool pedidoEsValido(Repartidor[], int, Pedido);
void agregarPedido(ListaColaPedidos*&, Pedido);
Repartidor* buscarRepartidor(int dniRepartidor,Repartidor repartidores[], int cantidadRepartidoresActuales);
NodoPedido* buscarPedido(Repartidor* repartidor, ListaColaPedidos* listaColaPedidos);
void desencolarPedido(ListaColaPedidos*& listaColaPedidos, Pedido pedido);
void asignarPedido(Repartidor repartidores[], int cantidadRepartidoresActuales, ListaColaPedidos*& listaColaPedidos, NodoArbol*& raiz);
void agregarAlArbol(NodoArbol*& raiz, Pedido pedido);
NodoArbol* buscarEnArbol(NodoArbol* raiz,Pedido pedido);
void insertarEnArbol(NodoArbol*& raiz, Pedido pedido);
void agregarPedidoColaPedidos(ColaPedidos*& colaPedidos, Pedido pedido);
void agregarPedidoListaPedidosEntregadosRepartidor(Repartidor*& repartidor, Pedido pedido);
void desencolarPedidoColaPedidos(ColaPedidos*& colaPedidos, Pedido pedido);

void ingresarPedido(Repartidor repartidores[], int cantidadRepartidoresActuales, ListaColaPedidos*& listaColaPedidos) {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  Pedido newPedido;
  bool error = false;
  bool errorPaqueteValido = false;
  string input = "";

  do { // Loop hasta ingresar un paquete valido
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
    
    do { // Input zona loop
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

    do { // Input volumen loop
      system("cls");
      if (error) cout << "Volumen erroneo!"<<endl<<endl;
      cout << "Ingrese el volumen del pedido en m3"<<endl<<endl;

      getline(cin, input);
      float validInput;
      try {
        validInput = stof(input); // TODO: comprobar que este casteo anda 100% bien, no parece tener problemas de momento.
        if (validInput == 0) error = true;
        else {
          newPedido.volumen = validInput;
          error = false;
        }
      } catch(exception& e) {
        error = true;
      } 
    } while(error);
    
    if(!pedidoEsValido(repartidores, cantidadRepartidoresActuales, newPedido)) errorPaqueteValido = true;
    else errorPaqueteValido = false;
  
  } while(errorPaqueteValido);

  do { // Input importe loop
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
  agregarPedido(listaColaPedidos, newPedido);
}


// Se lo agrega al repartidor
void asignarPedido(Repartidor repartidores[], int cantidadRepartidoresActuales, ListaColaPedidos*& listaColaPedidos, NodoArbol*& raiz) {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  string input;
  bool error = false;

  int dniRepartidor;
  
  do { // input dni loop
    system("cls");
    if (error) {
      cout << "Formato de DNI Invalido!" << endl;
      cout << "Por favor, ingrese un DNI valido de un repartidor al que se le asignara un pedido: ";
    }
    else cout<<"DNI del repartidor al que se le asignara un pedido: ";
    
    getline(cin, input);
    if (!containsOnlyDigits(input) || cin.fail()) {
      error = true;
    }
    else {
      error = false;
      dniRepartidor = stoi(input);
    } 
  } while(error);

  Repartidor* punteroRepartidor = buscarRepartidor(dniRepartidor, repartidores, cantidadRepartidoresActuales);

  if(punteroRepartidor == NULL) {
    system("cls");
    cout<<"No existe un repartidor con DNI: " << dniRepartidor << endl << endl;
    cout << "Ingrese cualquier numero para volver" << endl << endl;
    cin >> input;
    return;
  }

  NodoPedido* nodoPedidoEncontrado = buscarPedido(punteroRepartidor, listaColaPedidos);

  if(nodoPedidoEncontrado == NULL) {
    system("cls");
    cout<<"No hay pedidos para asignar" << endl << endl;
    cout << "Ingrese cualquier numero para volver" << endl << endl;
    cin >> input;
    return;
  }

  agregarPedidoListaPedidosEntregadosRepartidor(punteroRepartidor, nodoPedidoEncontrado->pedido);
  agregarAlArbol(raiz, nodoPedidoEncontrado->pedido);
  desencolarPedido(listaColaPedidos, nodoPedidoEncontrado->pedido);
}

Repartidor* buscarRepartidor(int dniRepartidor, Repartidor repartidores[], int cantidadRepartidoresActuales){
  for(int i = 0; i < cantidadRepartidoresActuales; i++) {
    if (repartidores[i].dni == dniRepartidor) {
      Repartidor* punteroRepartidor = &repartidores[i];
      return punteroRepartidor; 
    }
  }
  return NULL; 
}

void agregarPedido(ListaColaPedidos*& listaColaPedidos, Pedido pedido) {
  ListaColaPedidos* actual = listaColaPedidos;
  ListaColaPedidos* anterior = listaColaPedidos;
  anterior = actual;

  while(actual != NULL) {
    if (actual->zona == pedido.zonaDeEntrega && actual->tipoVehiculo == Vehiculos(determinarVehiculoDelPedido(pedido))) {
      agregarPedidoColaPedidos(actual->colaPedidos, pedido);
      return;
    }
    anterior = actual;
    actual = actual->siguienteCola;
  }
  // Llegue al final o lista vacia, tengo que agregar una nueva cola
  if (actual == NULL) {
    ColaPedidos* nuevaColaPedidos = new ColaPedidos;
    nuevaColaPedidos->primero = NULL;
    nuevaColaPedidos->ultimo = NULL;
    agregarPedidoColaPedidos(nuevaColaPedidos, pedido);

    ListaColaPedidos* newListaColaPedidos = new ListaColaPedidos;
    newListaColaPedidos->tipoVehiculo = Vehiculos(determinarVehiculoDelPedido(pedido));
    newListaColaPedidos->zona = pedido.zonaDeEntrega;
    newListaColaPedidos->colaPedidos = nuevaColaPedidos;
    if (actual == listaColaPedidos) listaColaPedidos = newListaColaPedidos;
    else anterior->siguienteCola = newListaColaPedidos;
    return;
  }
}


bool pedidoEsValido(Repartidor repartidores[], int cantidadRepartidoresActuales, Pedido pedido) {
  Vehiculos vehiculoPedido = Vehiculos(determinarVehiculoDelPedido(pedido));
  for(int i = 0; i < cantidadRepartidoresActuales; i++) {
    if (repartidores[i].zona == pedido.zonaDeEntrega && repartidores[i].vehiculo.tipo == vehiculoPedido) { 
      return true;
    }
  }
  return false;
}

NodoPedido* buscarPedido(Repartidor* repartidor, ListaColaPedidos* listaColaPedidos) {
  while(listaColaPedidos != NULL) {
    if(listaColaPedidos->zona == repartidor->zona && listaColaPedidos->tipoVehiculo == repartidor->vehiculo.tipo){
      return listaColaPedidos->colaPedidos->primero;
    }
    listaColaPedidos = listaColaPedidos->siguienteCola;
  }
  return NULL;
}


void desencolarPedido(ListaColaPedidos*& listaColaPedidos, Pedido pedido) {
  ListaColaPedidos* actual = listaColaPedidos;
  ListaColaPedidos* anterior = listaColaPedidos;

  // una sola lista de colas
  if (actual->siguienteCola == NULL) {
    desencolarPedidoColaPedidos(actual->colaPedidos, pedido);
    return;
  }

  while(actual != NULL) {
    if(actual->zona == pedido.zonaDeEntrega && actual->tipoVehiculo == Vehiculos(determinarVehiculoDelPedido(pedido))) {
      desencolarPedidoColaPedidos(actual->colaPedidos, pedido);
      return;
    }
    anterior = actual;
    actual = actual->siguienteCola;
  }
}


void agregarAlArbol(NodoArbol*& raiz, Pedido pedido){
  NodoArbol* n;
  n = buscarEnArbol(raiz,pedido);
  if(n == NULL){
    insertarEnArbol(raiz,pedido);
  }
  else{
    n->ventas++;
  }
}

NodoArbol* buscarEnArbol(NodoArbol* raiz,Pedido pedido){
  NodoArbol*r=raiz;
    while(r!=NULL && r->codigoComercio != pedido.codigoComercio)
    {
        if(pedido.codigoComercio < r->codigoComercio)
            r = r->izquierda;
        else
            r = r->derecha;
    }
    return r;
}

void insertarEnArbol(NodoArbol*& raiz, Pedido pedido){
  NodoArbol*n = new NodoArbol;
    n->codigoComercio = pedido.codigoComercio;
    n->ventas = 1;
    n->izquierda=NULL;
    n->derecha=NULL;
    if(raiz == NULL)
        raiz = n;
    else
    {
        NodoArbol*r = raiz;
        NodoArbol*anterior;
        while(r!=NULL)
        {
            anterior = r;
            if(pedido.codigoComercio < r->codigoComercio)
                r = r->izquierda;
            else
                r = r->derecha;
        }
        if(pedido.codigoComercio < anterior->codigoComercio)
            anterior->izquierda = n;
        else
            anterior->derecha = n;
    }
}

void agregarPedidoColaPedidos(ColaPedidos*& colaPedidos, Pedido pedido) {
  NodoPedido* nuevoPedido = new NodoPedido;
  nuevoPedido->pedido = pedido;
  nuevoPedido->siguiente = NULL;

  if(colaPedidos->ultimo != NULL){
    colaPedidos->ultimo->siguiente = nuevoPedido;
    colaPedidos->ultimo = nuevoPedido;
  }
  else {
    colaPedidos->primero = nuevoPedido;
    colaPedidos->ultimo = colaPedidos->primero;
  }
}

void agregarPedidoListaPedidosEntregadosRepartidor(Repartidor*& repartidor, Pedido pedido) {
    if(repartidor->listaPedidosEntregados == NULL) {
      repartidor->listaPedidosEntregados = new NodoPedido;
      repartidor->listaPedidosEntregados->pedido = pedido;
      repartidor->listaPedidosEntregados->siguiente = NULL;
      return;
    }

    NodoPedido* actual = repartidor->listaPedidosEntregados;
    NodoPedido* anterior = repartidor->listaPedidosEntregados;
    NodoPedido* nuevoNodo = new NodoPedido;
    nuevoNodo->pedido = pedido;

    while(actual != NULL && actual->pedido.importe < pedido.importe) {
      anterior = actual;
      actual = actual->siguiente;
    }
    if (actual == repartidor->listaPedidosEntregados) {
      nuevoNodo->siguiente = actual; 
      repartidor->listaPedidosEntregados = nuevoNodo;
      return;
    }
    nuevoNodo->siguiente = actual;
    anterior->siguiente = nuevoNodo;
  }

void desencolarPedidoColaPedidos(ColaPedidos*& colaPedidos, Pedido pedido) {
  if (colaPedidos->ultimo == NULL){
    colaPedidos->primero = NULL;
    return;
  }

  NodoPedido* primero = colaPedidos->primero;
  colaPedidos->primero = colaPedidos->primero->siguiente;
  delete primero;
  // if (colaPedidos->primero == colaPedidos->ultimo) {
  //   delete colaPedidos->ultimo;
  //   colaPedidos->primero->siguiente = NULL;
  //   colaPedidos->ultimo = NULL;
  // }
}