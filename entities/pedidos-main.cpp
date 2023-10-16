#include "./repartidores-actions.h"
#include "../../shared/model/repartidor.model.h"
#include "../../shared/utils/file-utils.h"
#include "../../shared/utils/general-utils.h"
using namespace std;

void printMenuPedidos(bool error);

pedidosMain()
{
    bool error = false;
    int userInput = 999;
    do {
        printMenuPedidos(error);
        cin >> userInput;
        if (cin.fail()) {
            error = true;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            userInput = 999;
        }
        switch(userInput)
        {
            case 1:
                error = false;
                ingresarPedido();
                break;
            case 2:
                error = false;
                asignarPedido();
                break;
            case 3:
                error = false;
                mostarRepartidores();
                break;
            case 0:
                return;
            default:
            error = true;    

        }
    }
}

void printMenuPedidos(bool error)
{
    system("cls");
  if (error) cout<<"Opcion incorrecta!"<<endl<<endl;
  cout<<"1 - Recibir un pedido"<<endl;
  cout<<"2 - Asignar pedido a un repartidor"<<endl;
  cout<<"3 - Mostrar repartidores"<<endl;
  cout<<"0 - Volver"<<endl<<endl; 
}
