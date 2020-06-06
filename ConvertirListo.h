
void ConvertirListos(){

    string line;
    ifstream Listos("ClientesListos.txt");
    ofstream Excel;
    int cont = 0;

    string Titulo = "- Codigo. - Nombre. - Marco. - Pintura. - Direccion. - Fecha.";

    remove("ClientesListos.csv");
    Excel.open("ClientesListos.csv", ios::app);

    for(int i = 0; i < 60; i++)
    {
        if(Titulo[i] == '-')
        {
            for(int j = 0; j < 1000; j++)
            {
                if(Titulo[i + j] == '.')
                {
                    Excel << Titulo.substr(i + 1, j - 1) << ";";
                    j = 1000;
                }
            }
            cont++;
            if(cont == 6)
            {
                Excel << "\n";
            }
        }
    }

    while(getline(Listos, line))
    {
        for(int i = 0; i < 20; i++)
        {
            if(line[i] == ':')
            {
                Excel << line.substr(0, i) << ";";
                cont = 1;
                i = 20;
            }
            else if(line[i] == '-')
            {
                for(int j = 0; j < 1000; j++)
                {
                    if(line[i + j] == '.')
                    {
                        Excel << line.substr(i + 1, j - 1) << ";";
                        j = 1000;
                    }
                }
                cont++;
                i = 20;
                if(cont == 6)
                {
                    Excel << "\n";
                }
            }
        }
    }

    Listos.close();
    Excel.close();

}

