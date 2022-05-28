#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.hpp"

using namespace std;

void cambiosusuarios(void);
void bajasusuarios(void);
void altasusuarios(void);

void Usuaios(void){
	
	int i;
	bool repetir=true;
	
	do
	{
	system("cls");
	
	cout<<"\n -----------Menu de Opciones de Usuarios--------------"<<endl;
	cout<<"- Opcion 1: Altas                                    -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 2: Bajas                                    -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 3: Cambios                                  -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 5: Regresar al Menu Principal                -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"\n\n Elija una Opcion: ";
	cin>>i;
	
	system("cls");
	
	switch(i)
	{
		case 1:
			altasusuarios();
		break;
		
		case 2:	
			bajasusuarios();
		break;
		
		case 3:
			cambiosusuarios();
		break;
		
		case 5:
		repetir = false;
		break;
		
		default:
		cout<<"\n Opcion Incorrecta";
		break;
	}
	
	}while(repetir);
}


void altasusuarios(void){

	FILE *usuarios;
	char auxnom[50], auxcontra[50];
	
	struct usuarios Usuario;
	
	cout<<"\n\r REGISTRO DE USUARIOS";
	usuarios =fopen("Usuarios.txt", "r+");
	
	if(usuarios==NULL){
		usuarios=fopen("Usuarios.txt","w+");
		cout<<"\n ARCHIVO CREADO INTENTE OTRA VEZ";
		getch();
		return;
	} 
	
		cout<<"\n-----------------------------------------------------"<<endl;	
		cout<<"\nIngrese el nombre del Usuario: ";
	    cin>>auxnom;
	    cout<<"\n-----------------------------------------------------"<<endl;
	    
	    fread(&Usuario, sizeof(Usuario), 1,usuarios);
	    while(!feof(usuarios)){
	    	
	    	if(strcmp(Usuario.usuario, auxnom)==0){
	    		cout<<"\n ERROR YA EXISTE ESE USUARIO";
	    		fclose(usuarios);
	    		getch();
	    		return;
			}
			fread(&Usuario, sizeof(Usuario), 1,usuarios);
		}
		
			strcpy(Usuario.usuario, auxnom);
			cout<<"\n-----------------------------------------------------"<<endl;	
			cout<<"\n Ingrese el Password: ";
			cin>>auxcontra;
	        cout<<"\n-----------------------------------------------------"<<endl;
	        
	         fread(&Usuario, sizeof(Usuario), 1,usuarios);
	  		  while(!feof(usuarios)){
	    	
	    	if(strcmp(Usuario.contrasena, auxcontra)==0){
	    		cout<<"\n ERROR PRUEBE CON OTRA PASSWORD";
	    		fclose(usuarios);
	    		getch();
	    		return;
			}
			fread(&Usuario, sizeof(Usuario), 1,usuarios);
		}
	     
	     	strcpy(Usuario.contrasena, auxcontra);
			cout<<"\n Ingrese el tipo de usuario que es: ";
			cin>>Usuario.tipo;
			cout<<"\n Registro Creado";
			fwrite(&Usuario, sizeof(Usuario), 1,usuarios);
			fclose(usuarios);
			system("pause>nul");  	
	
}

void bajasusuarios(void){
	
	FILE *usuarios;
	char auxnom[50],auxcontra[50],op;
	
	struct usuarios Usuario;
	cout<<"\n\r BAJAS DE LOS Usuarios";
	
	usuarios =fopen("Usuarios.txt", "r+");
	
	if(usuarios==NULL){
		cout<<"\n NO EXISTE EL ARCHIVO";
		fclose(usuarios);
		getch();
		return;
	}
	
	cout<<"\n Ingrese el Nombre del Usuario: ";
	cin>>auxnom;
	cout<<"\n Ingrese la Password del usuario: ";
	cin>>auxcontra;
	
		fread(&Usuario, sizeof(Usuario), 1,usuarios);
	    while(!feof(usuarios)){
	    	
	    	if(strcmp(Usuario.usuario, auxnom)==0){
	    		
	    		if(strcmp(Usuario.contrasena, auxcontra)==0){
				
	    		cout<<"\n-----------------------------------"<<endl;
	    		cout<<"\n Nombre del usuario: "<<Usuario.usuario<<endl;
	    		cout<<" Password del usuario: "<<Usuario.contrasena<<endl;
	    		cout<<" Tipo de usuario: "<<Usuario.tipo<<endl;
	    		cout<<"\n-----------------------------------"<<endl;
	    		
	    		strcpy(Usuario.usuario, "----");
	    		strcpy(Usuario.contrasena, "----");
	    		strcpy(Usuario.tipo, "----");
	    		
	    		do{
	    		cout<<"\n\nDesea eliminar el Registro? [S/N]: ";
				cin>>op;	
				op=toupper(op);
				}while(op!='S' && op!='N');
				
					if(op == 'S')
				{
					fseek(usuarios, ftell(usuarios)-sizeof(Usuario), SEEK_SET);
					fwrite(&Usuario, sizeof(Usuario), 1,usuarios);
					cout<<"\n REGISTRO ELIMINADO!!!";
				}		
				fclose(usuarios);
				getch();
				return;
				}
			}
			fread(&Usuario, sizeof(Usuario), 1,usuarios);
		}
		cout<<"\nNO SE ENCUENTRA EL REGISTRO";
		fclose(usuarios);
		getch();
		return;	
}

void cambiosusuarios(void){
	
	bool rep=false;
	FILE *usuarios;
	char auxnom[50],auxcontra[50],op;
	
	struct usuarios Usuario;
	cout<<"\n\r CAMBIOS DE LOS Usuarios";
	
	usuarios =fopen("Usuarios.txt", "r+");
	
	if(usuarios==NULL){
		cout<<"\n NO EXISTE EL ARCHIVO";
		fclose(usuarios);
		getch();
		return;
	}
	
	cout<<"\n Ingrese el Nombre del Usuario: ";
	cin>>auxnom;
	cout<<"\n Ingrese la Password del usuario: ";
	cin>>auxcontra;
	
		fread(&Usuario, sizeof(Usuario), 1,usuarios);
	    while(!feof(usuarios)){
	    	
	    	if(strcmp(Usuario.usuario, auxnom)==0){
	    		
	    		if(strcmp(Usuario.contrasena, auxcontra)==0){
	    			
				cout<<"\nLos Datos del Usuario son: ";
	    		cout<<"\n-----------------------------------"<<endl;
	    		cout<<"\n Nombre del usuario: "<<Usuario.usuario<<endl;
	    		cout<<" Password del usuario: "<<Usuario.contrasena<<endl;
	    		cout<<" Tipo de usuario: "<<Usuario.tipo<<endl;
	    		cout<<"\n-----------------------------------"<<endl;
	    		
	    			system("pause");
					system("cls");
					
						do{
				
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Que desea cambiar:              -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Cambiar Nombre: Opcion 1.       -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Cambiar Password: Opcion 2.      -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Cambiar Tipo: Opcion 3.        -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Terminar o Cancelar: Opcion 0.  -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"\n\n Elija una Opcion: ";
							cin>>op;
							
							switch(op)
							{
								case 1:
									system("cls");
									
									cout<<"\nIngrese el Nuevo Nombre del Usuario: ";
									cin>>Usuario.usuario;
									system("cls");
								break;
								
								case 2:
									system("cls");
									cout<<"\nIngrese la Nueva Password del Usuario: ";
									cin>>Usuario.contrasena;
									system("cls");
								break;
								
								case 3:
									system("cls");
									cout<<"\nIngrese el Nuevo tipo de Usuario: ";
									cin>>Usuario.tipo;
									system("cls");
								break;

								case 0:
									rep = false;
								break;
								
								default:
									cout<<"\n Opcion Incorrecta";
								break;
							}
							}while(rep);
							
							fseek(usuarios, ftell(usuarios)-sizeof(Usuario), SEEK_SET);
							fwrite(&Usuario, sizeof(Usuario), 1,usuarios);
							
							fclose(usuarios);
							cout<<"\n\n EL REGISTRO HA SIDO MODIFICADO";
								getch();
								return;	
							}
						 }
							fread(&Usuario, sizeof(Usuario), 1,usuarios);
						}
						cout<<"\nNO SE ENCONTRO AL USUARIO CON ESA CREDENCIALES!!!";
						fclose(usuarios);
						getch();
						return;	
}