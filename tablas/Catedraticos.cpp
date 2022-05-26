#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.hpp"

using namespace std;

void altascatedraticos(void);
void bajascatedraticos(void);
void cambisocatedraticos(void);

void catedraticos(void){
	
	int i;
	bool repetir=true;
	
	do
	{
	system("cls");
	
	cout<<"\n -----------Menu de Opciones de Catedraticos-------------"<<endl;
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
			altascatedraticos();
		break;
		
		case 2:	
			bajascatedraticos();
		break;
		
		case 3:
			cambisocatedraticos();
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

void altascatedraticos(void){
	
	FILE *catedraticos;
	
	char auxcod[50];
	struct tipo_catedraticos Catedraticos;
	
	cout<<"\n\r REGISTRO DE LOS CATEDRATICOS";
	
	catedraticos=fopen("Catedrativos.txt","r+");
	
	if(catedraticos==NULL){
		
		catedraticos=fopen("Catedrativos.txt","w+");
		cout<<"\n ARCHIVO CREADO INTENTE DE NUEVO";
		fclose(catedraticos);
		getch();
		return;
	}
	
		cout<<"\n-----------------------------------------------------"<<endl;	
		cout<<"\nIngrese el Codigo del catedratico ";
	    cin>>auxcod;
	    cout<<"\n-----------------------------------------------------"<<endl;
	    
	    fread(&Catedraticos, sizeof(Catedraticos), 1,catedraticos);
	    while(!feof(catedraticos)){
	    	
	    	if(strcmp(Catedraticos.codigo_catedratico, auxcod)==0){
	    		
	    		cout<<"\n YA EXISTE UN CATEDRATICO CON ESE CODIGO";
	    		fclose(catedraticos);
	    		getch();
	    		return;
			}
			fread(&Catedraticos, sizeof(Catedraticos), 1,catedraticos);
		}
		
		strcpy(Catedraticos.codigo_catedratico, auxcod);
		cout<<"\n Ingrese el titulo del catedratico: ";
		cin>>Catedraticos.titulo;
		cout<<"\n Ingrese el Nombre del catedratico: ";
		cin>>Catedraticos.nombre;
		cout<<"\n REGISTRO CREADO";
		fwrite(&Catedraticos, sizeof(Catedraticos), 1,catedraticos);
		fclose(catedraticos);
		system("pause>nul");
}

void bajascatedraticos(void){
	
	FILE *catedraticos;
	
	char auxcod[50],op;
	struct tipo_catedraticos Catedraticos;
	
	cout<<"\n\r BAJAS DE LOS CATEDRATICOS";
	
	catedraticos=fopen("Catedrativos.txt","r+");
	
	if(catedraticos==NULL){
		cout<<"\n NO EXISTE EL ARCHIVO";
		fclose(catedraticos);
		getch();
		return;
	}
	
	cout<<"\n Ingrese el codigo del catedratico que deseea eliminar: ";
	cin>>auxcod;
	
	 fread(&Catedraticos, sizeof(Catedraticos), 1,catedraticos);
	    while(!feof(catedraticos)){
	    	
	    	if(strcmp(Catedraticos.codigo_catedratico, auxcod)==0){
	    		
	    		cout<<"\n-----------------------------------"<<endl;
	    		cout<<"\n Clave del Catedratico: "<<Catedraticos.codigo_catedratico<<endl;
	    		cout<<" Titulo del Catedratico: "<<Catedraticos.titulo<<endl;
	    		cout<<" Nombre del catedratico: "<<Catedraticos.nombre<<endl;
	    		cout<<"\n-----------------------------------"<<endl;
	    		
	    		strcpy(Catedraticos.codigo_catedratico, "----");
	    		strcpy(Catedraticos.nombre, "----");
	    		strcpy(Catedraticos.titulo, "----");
	    		
	    		do{
	    		cout<<"\n\nDesea eliminar el Registro? [S/N]: ";
				cin>>op;	
				op=toupper(op);
				}while(op!='S' && op!='N');
					
				if(op == 'S')
				{
					fseek(catedraticos, ftell(catedraticos)-sizeof(Catedraticos), SEEK_SET);
					fwrite(&Catedraticos, sizeof(Catedraticos), 1,catedraticos);
					cout<<"\n REGISTRO ELIMINADO!!!";
				}		
				fclose(catedraticos);
				getch();
				return;
					    	
			}
	    	
	    	fread(&Catedraticos, sizeof(Catedraticos), 1,catedraticos);
		}
		cout<<"\nNO SE ENCUENTRA EL REGISTRO";
		fclose(catedraticos);
		getch();
		return;	
	
}


void cambisocatedraticos(void){
	
		FILE *catedraticos;
		struct tipo_catedraticos Catedraticos;
		bool rep = true;
		char auxcod[50];
		int op;
		
		cout<<"\n\r CAMBIOS A LOS REGISTROS DE LOS CATEDRATICOS";
	
		catedraticos=fopen("Catedrativos.txt","r+");
		
		if(catedraticos==NULL){
		cout<<"\n NO EXISTE EL ARCHIVO";
		fclose(catedraticos);
		getch();
		return;
		}
		
			cout<<"\nIngrese la clave del catedratico que desea modificar: ";
			cin>>auxcod;
			 	fread(&Catedraticos, sizeof(Catedraticos), 1,catedraticos);
	    		while(!feof(catedraticos)){
	    	
	    		if(strcmp(Catedraticos.codigo_catedratico, auxcod)==0)
				{
					cout<<"\nLos Datos del catedratico son: ";
					cout<<"\n-----------------------------------"<<endl;
		    		cout<<"\n Clave del Catedratico: "<<Catedraticos.codigo_catedratico<<endl;
		    		cout<<" Titulo del Catedratico: "<<Catedraticos.titulo<<endl;
		    		cout<<" Nombre del catedratico: "<<Catedraticos.nombre<<endl;
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
							cout<<"- Cambiar titulo: Opcion 2.       -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Terminar o Cancelar: Opcion 0.  -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"\n\n Elija una Opcion: ";
							cin>>op;
							
							switch(op)
							{
								case 1:
									system("cls");
									
									cout<<"\nIngrese el Nuevo Nombre del Catedratico: ";
									cin>>Catedraticos.nombre;
									system("cls");
								break;
								
								case 2:
									system("cls");
									cout<<"\nIngrese el Nuevo titulo del Catedratico: ";
									cin>>Catedraticos.titulo;
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
							
							fseek(catedraticos, ftell(catedraticos)-sizeof(Catedraticos), SEEK_SET);
							fwrite(&Catedraticos, sizeof(Catedraticos), 1,catedraticos);
							
								fclose(catedraticos);
								cout<<"\n\n EL REGISTRO HA SIDO MODIFICADO";
								getch();
								return;	
							}
							fread(&Catedraticos, sizeof(Catedraticos), 1,catedraticos);
						}
						cout<<"\nNO SE ENCONTRO EL CATEDRATICO CON ESA CLAVE!!!";
						fclose(catedraticos);
						getch();
						return;		
}