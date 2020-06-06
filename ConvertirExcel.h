
void ConvertirExcel(){

    string line;
    ifstream Pendiente("ClientesPendientes.txt");
    ofstream Excel;
    int cont;

    remove("ClientesPendientes.csv");
    Excel.open("ClientesPendientes.csv", ios::app);

    while(getline(Pendiente, line))
    {
        for(int i = 0; i < 20; i++)
        {
            if(line[i] == ':')
            {
                Excel << line.substr(0, i) << " ";
                cont = 1;
                i = 20;
            }
            else if(line[i] == '-')
            {
                for(int j = 0; j < 1000; j++)
                {
                    if(line[i + j] == '.')
                    {
                        Excel << line.substr(i + 1, j - 1) << " ";
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

    Pendiente.close();
    Excel.close();

}
