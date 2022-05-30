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
	
	struct tipo_evaluacion Eva1;

	char aux[50];
	

	prueba1 =fopen("Prueba1.txt","r+");
	
	if(prueba1==NULL){
		
		cout<<"\n NO EXISTE EL ARCHIVO";
		fclose(prueba1);

		getch();
		return;
		
	}
	
	cout<<"\n\r REPORTE DE TODOS LOS ALUMNOS QUE REALIZARON LA EVALUACION";
		
	fread(&Eva1, sizeof(Eva1), 1,prueba1);
	while(!feof(prueba1)){	
	
		cout<<"\n-----------------------------------";
		cout<<"\n El Alumno con el Carnet: "<<Eva1.carnetalum;
		cout<<"\n YA HIZO LA EVALUACION";
		cout<<"\n-----------------------------------";
		
	fread(&Eva1, sizeof(Eva1), 1,prueba1);
	}
		fclose(prueba1);

		getch();
		return;	
}