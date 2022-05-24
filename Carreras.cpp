#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.h"

using namespace std;

void carreras(void){
	
	FILE *carrera;
	
	char auxcod[10];
	struct tipo_carrera  Carrera;
	
	cout<<"\n\r REGISTRO DE LAS CARRERAS";
	
	carrera = fopen("Carreras.txt","r+");
	
	if(carrera==NULL){
		
		carrera = fopen("Carreras.txt","w");
		cout<<"\n ARCHIVO CREADO INTENTE DE NUEVO";
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