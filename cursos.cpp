#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.h"


using namespace std;

void cursos(void){
	bool encontrado = false;
	FILE *carrera;
	FILE *cursos;
	
	char aux[50];
	char auxcod[10];
	
	struct tipo_carrera  Carrera;
	struct tipo_cursos Cursos;
	
	cout<<"\n\r REGISTRO DE CURSOS";
	
	cursos = fopen("Cursos.txt","r+");
	carrera = fopen("Carreras.txt","r+");
	
	if(cursos==NULL){
		
		cursos = fopen("Cursos.txt","w");
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
					cout<<"\n La carrera es : "<<Carrera.carrera<<endl;
	        		getch();
	        		encontrado = true;
				}
				fread(&Carrera, sizeof(Carrera), 1,carrera);
			}
		if(encontrado== false){
				cout<<"\n ERROR, no existe una carrera con esa clave"<<endl;
	        	fclose(cursos);
	        	fclose(carrera);
	        	getch();
	        	return;
		}
		
		strcpy(Carrera.cod_carrera, auxcod);
		
		cout<<"\n-----------------------------------------------------"<<endl;	
		cout<<"\nIngrese el Codigo del curso: ";
	    cin>>aux;
	    cout<<"\n-----------------------------------------------------"<<endl;
	    
	    fread(&Cursos, sizeof(Cursos), 1,cursos);
	    
	    	while(!feof(cursos)){
	    		
	    		if(strcmp(Cursos.cod_curso, aux)== 0){
	    			cout<<"\n ERROR, ya existe un curso con esa clave"<<endl;
	        		fclose(cursos);
	        		fclose(carrera);
	        		getch();
	        		return;
				}
				fread(&Cursos, sizeof(Cursos), 1,cursos);
			}
			
			strcpy(Cursos.cod_curso, aux);
			cout<<"\n Ingrese el nombre del curso: ";
			cin>>Cursos.nombre_curso;
			cout<<"\n Ingrese el ciclo del curso: ";
			cin>>Cursos.ciclo;
			cout<<"\n Registro Creado";
			fwrite(&Cursos, sizeof(Cursos), 1,cursos);
			fclose(cursos);
			fclose(carrera);
			system("pause>nul");
}