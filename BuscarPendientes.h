bool BuscarPendientes(string buscar){

    ifstream Pendiente("ClientesPendientes.txt");
    string line;
    string Nombre;
    bool Estado = false;
    int i = 6;

    if(Pendiente.is_open()){
       while(getline(Pendiente, line))
       {
           for(int j = 0; j < 20; j++){
                if(line[j] == ' ' || line[j] == ':'){
                    Nombre = line.substr(0,j);
                    //cout << Nombre << "jhfghdfg\n" << endl;

                    if(Nombre == buscar){
                         i = 0;
                         Estado = true;
                    }
                    j = 20;

                }
           }
           if(i < 6){
                cout << line << endl;
                i++;
           }
       }
    }
    else{
        cout << "no se abrio uwu";
    }

    Pendiente.close();

    return(Estado);

}

