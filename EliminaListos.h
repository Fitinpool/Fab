

bool EliminarListos(string Borrar){

    ofstream Temporal;
    ifstream Listos("ClientesListos.txt");
    string line;
    string Nombre;
    bool Estado = false;
    int i = 6;

    Temporal.open("Temporal.txt", ios::app);

    if(Listos.is_open()){
       while(getline(Listos, line))
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

    Listos.close();
    Temporal.close();

    remove("ClientesListos.txt");
    rename("Temporal.txt", "ClientesListos.txt");

    return(Estado);
}

