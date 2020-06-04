#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

void Ingreso(string Comprador, string Cuadro, string Pintura, string Direccion){

    string line;
    ofstream Formulario("Formulario.txt", ios::app);
    int i = 0;
    bool bandera = true;

    if(Formulario.is_open()){
        Formulario  << Comprador << ": \n\t- "
                    << Cuadro << ".\n\t- "
                    << Pintura << ".\n\t- "
                    << Direccion << "." << endl;
    }

    Formulario.close();

    system("cls");
}
