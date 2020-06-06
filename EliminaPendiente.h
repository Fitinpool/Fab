

bool EliminarPendiente(string Borrar){

    ofstream Temporal;
    ifstream Pendientes("ClientesPendientes.txt");
    string line;
    string Nombre;
    bool Estado = false;
    int i = 6;

    Temporal.open("Temporal.txt", ios::app);

    if(Pendientes.is_open()){
       while(getline(Pendientes, line))
       {
           for(int j = 0; j < 20; j++){
                if(line[j] == ' ' || line[j] == ':'){
                    Nombre = line.substr(0,j);
                    //cout << Nombre << "jhfghdfg\n" << endl;
                    if(Nombre == Borrar){
                        i = 0;
                        Estado = true;
                    }
                    j = 20;
                }
           }

           if(i < 6){
                i++;
           }
           else{
                Temporal << line << endl;
           }
       }
    }
    else{
        cout << "no se abrio uwu";
    }

    Pendientes.close();
    Temporal.close();

    remove("ClientesPendientes.txt");
    rename("Temporal.txt", "ClientesPendientes.txt");

    return(Estado);

}
