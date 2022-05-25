#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.hpp"

using namespace std;

void catedraticos_cursos(void){
	
	int i;
	bool repetir=true;
	
	do
	{
	system("cls");
	
	cout<<"\n -----Menu de Opciones de Catedraticos por cursos----"<<endl;
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
			
		break;
		
		case 2:	
			
		break;
		
		case 3:
			
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

void altasctdcursos(void){
	
	FILE *catedraticos;
	FILE *secciones;
	FILE *ctdcursos;
	
	struct tipo_catedraticos Catedraticos;
	struct tipo_seccion Seccion;
	struct tipo_catedraticos_cursos Ctd;
	
	bool encontra=false;
	bool encontrado=false;
	
	char auxcod[10],aux[50];
	
	cout<<"\n REGISTRO DE CATEDRATICOS POR CURSOS";
	
	catedraticos=fopen("Catedrativos.txt","r+");
	secciones = fopen("Secciones.txt","r+");
	ctdcursos =fopen("Catedraticos_cursos.txt", "r+");
	
	if(ctdcursos==NULL){
		
		ctdcursos =fopen("Catedraticos_cursos.txt", "w+");
		cout<<"\n ARCHIVO CREADO INTENTE DE NUEVO";
		fclose(ctdcursos);
		fclose(secciones);
		fclose(catedraticos);
		getch();
		return;
	}
	
		cout<<"\n-----------------------------------------------------"<<endl;	
		cout<<"\n Ingrese el Codigo de la seccion: ";
		cin>>auxcod;
		cout<<"\n-----------------------------------------------------"<<endl;
		
		fread(&Seccion, sizeof(Seccion), 1,secciones);
			while(!feof(secciones)){
				
				if(strcmp(Seccion.seccion, auxcod)==0){
					
				}
			}
}