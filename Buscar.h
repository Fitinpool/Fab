void Buscar(string buscar){

    ifstream Formulario("Formulario.txt");
    string line;
    string Nombre;
    int i = 5;

    if(Formulario.is_open()){
       while(getline(Formulario, line))
       {
           for(int j = 0; j < 20; j++){
                if(line[j] == ' ' || line[j] == ':'){
                    Nombre = line.substr(0,j);
                    //cout << Nombre << "jhfghdfg\n" << endl;
                    j = 20;
                }
           }

           if(Nombre == buscar){
                i = 0;
           }
           if(i < 4){
                cout << line << endl;
                i++;
           }
       }
    }
    else{
        cout << "no se abrio uwu";
    }

}
