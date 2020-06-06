
bool CambiarCliente(string Cambio){

    ofstream Temporal;
    ofstream Listo("ClientesListos.txt", ios::app);
    ifstream Pendiente("ClientesPendientes.txt");

    string line;
    string NumCodigo;

    bool Estado = false;

    int i = 6;

    Temporal.open("Temporal.txt", ios::app);

    if(Pendiente.is_open()){
       while(getline(Pendiente, line))
       {
           for(int j = 0; j < 20; j++){
                if(line[j] == ' ' || line[j] == ':'){
                    NumCodigo = line.substr(0,j);
                    //cout << Nombre << "jhfghdfg\n" << endl;
                    if(NumCodigo == Cambio){
                        i = 0;
                        Estado = true;
                    }
                    j = 20;
                }
           }

           if(i < 6)
           {
                Listo << line << endl;
                i++;
           }
           else
           {
               Temporal << line << endl;
           }
       }
    }
    else{
        cout << "no se abrio uwu";
    }

    Listo.close();
    Pendiente.close();
    Temporal.close();

    remove("ClientesPendientes.txt");
    rename("Temporal.txt", "ClientesPendientes.txt");

    return(Estado);

}

