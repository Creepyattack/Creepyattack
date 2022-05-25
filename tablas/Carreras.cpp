#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.hpp"

using namespace std;
void altascarrera(void);
void cambioscarrera(void);
void bajascarrera(void);

void carreras(void){
	
	int i;
	bool repetir=true;
	
	do
	{
	system("cls");
	
	cout<<"\n -----------Menu de Opciones de Carreras-------------"<<endl;
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
			altascarrera();
		break;
		
		case 2:	
			bajascarrera();
		break;
		
		case 3:
			cambioscarrera();
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
	
	void altascarrera(void)
	{
	
	FILE *carrera;
	
	char auxcod[10];
	struct tipo_carrera  Carrera;
	
	cout<<"\n\r REGISTRO DE LAS CARRERAS";
	
	carrera = fopen("Carreras.txt","r+");
	
	if(carrera==NULL){
		
		carrera = fopen("Carreras.txt","w");
		cout<<"\n ARCHIVO CREADO INTENTE DE NUEVO";
		fclose(carrera);
		getch();
		return;
	}
	
			cout<<"\n-----------------------------------------------------"<<endl;	
			cout<<"\nIngrese el Codigo de la Carrera: ";
	        cin>>auxcod;
	        cout<<"\n-----------------------------------------------------"<<endl;
	        
	        fread(&Carrera, sizeof(Carrera), 1,carrera);
	        
	        while(!feof(carrera)){
	        	
	        	if(strcmp(Carrera.cod_carrera, auxcod)== 0){
	        		
	        		cout<<"\n ERROR, ya existe una Carrera con esa clave"<<endl;
	        		fclose(carrera);
	        		getch();
	        		return;
				}
				fread(&Carrera, sizeof(Carrera), 1,carrera);
			}
			
			strcpy(Carrera.cod_carrera, auxcod);
			cout<<"\n Ingrese el nombre de la carrera: ";
			cin>>Carrera.carrera;
			cout<<"\n Registro Creado";
			fwrite(&Carrera, sizeof(Carrera), 1,carrera);
			fclose(carrera);
			system("pause>nul");
	
	}
	
	
	void bajascarrera(void)
	{
		char auxcod[10], op;
		FILE *carrera;
		struct tipo_carrera  Carrera;
		
		carrera = fopen("Carreras.txt","r+");
		if(carrera == NULL){
			cout<<"\nNO EXISTE EL ARCHIVO !!!";
			fclose(carrera);
			getch();
			return;
		}
		
		cout<<"\n Ingrese la clave de la carrera que desea Eliminar: ";
		cin>>auxcod;
		
		fread(&Carrera, sizeof(Carrera), 1,carrera);
		while(!feof(carrera)){
		    if(strcmp(Carrera.cod_carrera, auxcod)== 0)
			{
				cout<<"\n-----------------------------------"<<endl;
				cout<<"\n Clave de la carrera: "<<Carrera.cod_carrera<<endl;
				cout<<" Nombre de la carrera: "<<Carrera.carrera<<endl;
				cout<<"\n-----------------------------------"<<endl;
				
				strcpy(Carrera.cod_carrera, "----");
				strcpy(Carrera.carrera, "----");
				
				do{
				  cout<<"\n\nDesea eliminar el Registro? [S/N]: ";
				cin>>op;	
				op=toupper(op);
				}while(op!='S' && op!='N');
				
				if(op == 'S')
				{
					fseek(carrera, ftell(carrera)-sizeof(Carrera), SEEK_SET);
					fwrite(&Carrera, sizeof(Carrera), 1,carrera);
					cout<<"\n REGISTRO ELIMINADO!!!";
				}		
				fclose(carrera);
				getch();
				return;
			}
			fread(&Carrera, sizeof(Carrera), 1,carrera);
		}
		cout<<"\nNO SE ENCUENTRA EL REGISTRO";
		fclose(carrera);
		getch();
		return;	
	}
	
	void cambioscarrera(void){
		
		FILE *carrera;
		struct tipo_carrera  Carrera;
		bool rep = true;
		char auxcod[5];
		int op;
		
		cout<<"\n\r CAMBIOS A LOS REGISTROS DE LAS CARRERAS";
	
		carrera = fopen("Carreras.txt","r+");
		
		if(carrera==NULL){
			
			cout<<"\n NO EXISTE EL ARCHIVO";
			fclose(carrera);
			getch();
			return;
		}
		
			cout<<"\nIngrese la clave de la carrera que desea modificar: ";
			cin>>auxcod;
			
			fread(&Carrera, sizeof(Carrera), 1,carrera);
			while(!feof(carrera)){
			    if(strcmp(Carrera.cod_carrera, auxcod)== 0)
				{
					cout<<"\nLos Datos de la carrera son: ";
					cout<<"\n-----------------------------------"<<endl;
					cout<<"\n Clave de la carrera: "<<Carrera.cod_carrera<<endl;
					cout<<" Nombre de la carrera: "<<Carrera.carrera<<endl;
					cout<<"\n-----------------------------------"<<endl;
					
					cout<<"\n\n\n\r";
			
					system("pause");
					system("cls");
					
						do{
				
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Que desea cambiar:              -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Cambiar Nombre: Opcion 1.       -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Terminar o Cancelar: Opcion 0.  -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"\n\n Elija una Opcion: ";
							cin>>op;
							
							switch(op)
							{
								case 1:
									system("cls");
									
									cout<<"\nIngrese el Nuevo Nombre del Producto: ";
									cin>>Carrera.carrera;
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
							
							fseek(carrera, ftell(carrera)-sizeof(Carrera), SEEK_SET);
							fwrite(&Carrera, sizeof(Carrera), 1,carrera);
							
								fclose(carrera);
								cout<<"\n\n EL REGISTRO HA SIDO MODIFICADO";
								getch();
								return;	
							}
							fread(&Carrera, sizeof(Carrera), 1,carrera);
						}
						cout<<"\nNO SE ENCONTRO EL PRODUCTOS CON ESE CODIGO!!!";
						fclose(carrera);
						getch();
						return;		
	}
		