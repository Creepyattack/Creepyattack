#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.hpp"

using namespace std;

void reporteXalumnos(void){
	
	FILE *prueba1;
	FILE *alumno;
	
	struct tipo_evaluacion1 Eva1;
	struct tipo_alumno Alumno;
	
	alumno = fopen("Alumnos.txt", "r+");
	prueba1 =fopen("Prueba1.txt","r+");
	
	if(prueba1==NULL){
		
		cout<<"\n NO EXISTE EL ARCHIVO";
		fclose(prueba1);
		fclose(alumno);
		getch();
		return;
		
	}
	
	cout<<"\n\r REPORTE DE TODOS LOS ALUMNOS QUE REALIZARON LA EVALUACION";
	
	fread(&Eva1, sizeof(Eva1), 1,prueba1);
		while(!feof(prueba1)){
			cout<<"\n-----------------------------------";
			cout<<"\n Carnet del Estudiante: "<<Eva1.carnet1;
			
			fread(&Alumno, sizeof(Alumno), 1,alumno);
		   		while(!feof(alumno)){
		    	
			    	if(strcmp(Alumno.carnet, Eva1.carnet1)==0){
			    		
			    		cout<<"\n Nombre del Alumno: "<<Alumno.nombre_alumno;
			    		cout<<"\n YA HIZO LA EVALUACION";
						cout<<"\n-----------------------------------";	
					}
					fread(&Alumno, sizeof(Alumno), 1,alumno);
				}
			fread(&Eva1, sizeof(Eva1), 1,prueba1);	
		}
		
		fclose(prueba1);
		fclose(alumno);
		getch();
		return;	
}