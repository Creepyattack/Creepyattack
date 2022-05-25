#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <vector>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

using namespace std;
void admin(void);

void admincontra(void){
	
	vector<string> usuarios;
    vector<string> claves;


    usuarios.push_back("Jose");
    usuarios.push_back("Pedro");
    usuarios.push_back("Juan");
    usuarios.push_back("Maurisio");
    usuarios.push_back("Kevin");

 
    claves.push_back("123");
    claves.push_back("456");
    claves.push_back("789");
    claves.push_back("abc");
    claves.push_back("efg");

    string usuario, password;

    int contador = 0;
    bool ingresa = false;
	
    do
    {
        system("cls");
        system("color B1");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tPassword: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
        	system("color C0");
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
    	system("color 20");
        cout << "\n\n\tBienvenido al sistema" << endl;
        getch();
        admin();
    }

    cin.get();
	
}