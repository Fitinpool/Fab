/*
    Horas Trabajadas = 5 horas 30 min.

    version test.
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

#include "Ingreso.h"
#include "MostrarPendientes.h"
#include "MostrarListos.h"
#include "CambiarCliente.h"
#include "BuscarPendientes.h"
#include "BuscarListos.h"
#include "EliminaPendiente.h"
#include "EliminaListos.h"
#include "ConvertirPendiente.h"
#include "ConvertirListo.h"

int main(){

    string Comprador, Cuadro, Pintura, Direccion, Fecha, NumCompra;
    string CambioCliente;
    string Busca;
    string Borrar;
    bool Bandera = true;
    int Opcion;

    while(Bandera){
        system("cls");
        cout << "Ingrese opcion: \n"
             << "1) Ingresar Cliente.\n"
             << "2) Mostrar Clientes Pendientes.\n"
             << "3) Mostrar Clientes Listos.\n"
             << "4) Mover Cliente Pendiente -> Listo.\n"
             << "5) Buscar Cliente (Pendientes).\n"
             << "6) Buscar Cliente (Listo).\n"
             << "7) Eliminar Cliente (Pendiente).\n"
             << "8) Eliminar Cliente (Listo).\n"
             << "9) Salir."
             << endl;

        cout << "Opcion Elegida: "; cin >> Opcion;

        if(Opcion == 1)
        {
            cin.ignore();
            cout << "Nombre comprador: "; getline(cin, Comprador);
            cout << "Tipo de cuadro: "; getline(cin, Cuadro);
            cout << "Pintura: "; getline(cin, Pintura);
            cout << "Direccion: "; getline(cin, Direccion);
            cout << "Fecha(dd/mm/aaaa): "; getline(cin, Fecha);
            cout << "Numero De Compra: "; getline(cin, NumCompra);

            Ingreso(Comprador, Cuadro, Pintura, Direccion, Fecha, NumCompra);
        }
        else if(Opcion == 2)
        {
            cout << "-----------------------------CLIENTES PENDIENTES-----------------------------" << endl;
            MostrarPendientes();
            system("pause");
        }
        else if(Opcion == 3)
        {
            cout << "-----------------------------CLIENTES LISTO-----------------------------" << endl;
            MostrarListos();
            system("pause");
        }
        else if(Opcion == 4)
        {
            cin.ignore();
            cout << "-----------------------------CAMBIO CLIENTE PENDIENTE -> LISTO-----------------------------" << endl;
            cout << "Ingrese el codigo del cliente: "; getline(cin, CambioCliente);
            if(CambiarCliente(CambioCliente)){
                cout << "Cambio Exitoso." << endl;
                system("pause");
            }
            else{
                cout << "No se encontro el cliente " << CambioCliente << " en lista pendiente." <<endl;
                system("pause");
            }
        }
        else if(Opcion == 5)
        {
            cin.ignore();
            cout << "-----------------------------BUSCAR CLIENTE EN PENDIENTE.-----------------------------" << endl;
            cout << "Ingrese el codigo del cliente: "; getline(cin, Busca);
            if(BuscarPendientes(Busca)){
                system("pause");
            }
            else{
                cout << "No se encontro el cliente " << CambioCliente << " en lista pendientes." <<endl;
                system("pause");
            }

        }
        else if(Opcion == 6)
        {
            cin.ignore();
            cout << "-----------------------------BUSCAR CLIENTE EN LISTO.-----------------------------" << endl;
            cout << "Ingrese el codigo del cliente: "; getline(cin, Busca);
            if(BuscarListos(Busca)){
                system("pause");
            }
            else{
                cout << "No se encontro el cliente " << CambioCliente << " en lista listos." <<endl;
                system("pause");
            }

        }
        else if(Opcion == 7)
        {
            cin.ignore();
            cout << "-----------------------------BORRAR CLIENTE EN PENDIENTE.-----------------------------" << endl;
            cout << "Ingrese el codigo del cliente: "; getline(cin, Borrar);
            if(EliminarPendiente(Borrar)){
                cout << "Eliminado Exitoso." << endl;
                system("pause");
            }
            else{
                cout << "No se encontro el cliente " << Borrar << " en lista pendiente." <<endl;
                system("pause");
            }

        }
        else if(Opcion == 8)
        {
            cin.ignore();
            cout << "-----------------------------BORRAR CLIENTE EN LISTO.-----------------------------" << endl;
            cout << "Ingrese el codigo del cliente: "; getline(cin, Borrar);
            if(EliminarListos(Borrar)){
                cout << "Eliminado Exitoso." << endl;
                system("pause");
            }
            else{
                cout << "No se encontro el cliente " << Borrar << " en lista listos." <<endl;
                system("pause");
            }

        }
        else if(Opcion == 9)
        {
            Bandera = false;
        }
    }

    ConvertirPendientes();
    ConvertirListos();

    return 0;
}
