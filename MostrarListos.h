
void MostrarListos(){

    ifstream Formulario("ClientesListos.txt");
    string line;

    if(Formulario.is_open()){
       while( getline(Formulario, line))
       {
            cout << line << endl;
       }
    }
    else{
        cout << "no se abrio uwu";
    }

    Formulario.close();


}
