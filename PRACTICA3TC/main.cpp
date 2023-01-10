#include "header.h"

signed main()
{
    int opcion;
    vector<string> validas = {"A2=A1+12+C5;", "AB=A*B/100-59;", "ABC=(340%2)+(12-C);", "AC=10+8*(5+B);", "VAR=CatA+((CatA+CatB)*CatC);"};
    vector<string> invalidas = {"3=A2=1+12+C5;", "AB=A**B/100-59;", "ABC(340%2);"};

    do
    {
        menu();
        cin >> opcion;

        if (opcion == 1)
        {
            // CADENAS DEFINIDAS
            cout << "Cadenas validas: " << endl;
            for (int i = 0; i < validas.size(); i++)
            {

                if (automataStack(validas[i]))
                {
                    cout << "Cadena valida: " << validas[i] << endl;
                }
                else
                {
                    cout << "Cadena invalida: " << validas[i] << endl;
                }
            }

            cout << endl
                 << "Cadenas invalidas: " << endl;
            for (int i = 0; i < invalidas.size(); i++)
            {

                if (automataStack(invalidas[i]))
                {
                    cout << "Cadena valida: " << invalidas[i] << endl;
                }
                else
                {
                    cout << "Cadena invalida: " << invalidas[i] << endl;
                }
        
            }
        }
        else if (opcion == 2)
        {
            // CADENAS INGRESADAS
            int cantidad;
            cout << "Ingrese la cantidad de cadenas a validar: ";
            cin >> cantidad;
            vector<string> cadenas;

            for (int i = 0; i < cantidad; i++)
            {
                string cadena;
                cout << "Ingrese la cadena " << i + 1 << ": ";
                cin >> cadena;
                cadenas.push_back(cadena);
            }

            for (int i = 0; i < cantidad; i++)
            {

                if (automataStack(cadenas[i]))
                {
                    cout << "Cadena valida: " << cadenas[i] << endl;
                }
                else
                {
                    cout << "Cadena invalida: " << cadenas[i] << endl;
                }
            }

        }

    } while (opcion != 3);

    cout << "Hasta luego :)" << endl;

    return 0;
}