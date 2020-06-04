void Eliminar(string Borrar){

    ofstream Temporal;
    ifstream Formulario("Formulario.txt");
    string line;
    string Nombre;
    string vacio;
    int i = 4;

    Temporal.open("Temporal.txt", ios::app);

    if(Formulario.is_open()){
       while(getline(Formulario, line))
       {
           for(int j = 0; j < 20; j++){
                if(line[j] == ' ' || line[j] == ':'){
                    Nombre = line.substr(0,j);
                    //cout << Nombre << "jhfghdfg\n" << endl;
                    if(Nombre == Borrar){
                        i = 0;
                    }
                    j = 20;
                }
           }

           if(i < 4){
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

    Formulario.close();
    Temporal.close();

    remove("Formulario.txt");
    rename("Temporal.txt", "Formulario.txt");

}
