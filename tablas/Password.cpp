#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.hpp"

using namespace std;

void catedraticosmenu(void);
void admin(void);
void usermenu(void);

void Password(void){
	bool encontrado=false;
	bool encontra=false;
	FILE *usuarios;
	system("cls");
	char auxnom[50], auxcontra[50];
	struct usuarios Usuario;
	usuarios =fopen("Usuarios.txt", "r+");
	
	 	cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout<<"\n\t Usuario: ";
        cin>>auxnom;
        cout<<"\n\t Password: ";
        cin>>auxcontra;
        
        fread(&Usuario, sizeof(Usuario), 1,usuarios);
	    while(!feof(usuarios)){
	    	
	    	if(strcmp(Usuario.usuario, auxnom)==0){
	    		encontra=true;
	    		if(strcmp(Usuario.contrasena, auxcontra)==0){
	    			encontrado=true;
	    			cout<<"\n\t Tipo de usuario: "<<Usuario.tipo<<endl;
	    			
	    			if(strcmp(Usuario.tipo, "Administrador")==0){
	    				cout<<"\n\t BIENVENIDO AL SISTEMA";
	    				getch();
	    				admin();
	    				
					}
						if(strcmp(Usuario.tipo, "Catedratico")==0){
	    				cout<<"\n\t BIENVENIDO AL SISTEMA";
	    				getch();
	    				catedraticosmenu();
	    				
					}
					
						if(strcmp(Usuario.tipo, "SA")==0){
	    				cout<<"\n\t BIENVENIDO AL SISTEMA";
	    				getch();
	    				usermenu();
	    				
					}
	    		}
	    	}
	    	fread(&Usuario, sizeof(Usuario), 1,usuarios);
		}
		
		if(encontrado==false || encontra==false){
		cout<<"\n\t Usuario o Password Incorrectos";
		fclose(usuarios);
		getch();
		return;
	}
}