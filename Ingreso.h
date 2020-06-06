
void Ingreso(string Comprador, string Cuadro, string Pintura, string Direccion, string Fecha, string NumCompra){

    string line;
    ofstream Formulario("ClientesPendientes.txt", ios::app);
    int i = 0;
    bool bandera = true;

    if(Formulario.is_open()){
        Formulario  << "#" << NumCompra << ": \n\t- "
                    << Comprador << ".\n\t- "
                    << Cuadro << ".\n\t- "
                    << Pintura << ".\n\t- "
                    << Direccion << ".\n\t- "
                    << Fecha << "."
                    << endl;
    }

    Formulario.close();

    system("cls");
}
