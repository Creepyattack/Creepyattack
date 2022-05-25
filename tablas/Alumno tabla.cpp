#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.hpp"

using namespace std;

void alumnos(void){
	
	int i;
	bool repetir=true;
	
	do
	{
	system("cls");
	
	cout<<"\n -----------Menu de Opciones de Alumnos--------------"<<endl;
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

void altasalumnos(void){
	
	bool encontrado = false;
	FILE *alumno;
	FILE *carrera;
	char auxcod[50],aux[10];
	struct tipo_alumno Alumno;
	struct tipo_carrera  Carrera;
	
	cout<<"\n\r REGISTRO DE ALUMNOS";
	alumno = fopen("Alumnos.txt", "r+");
	
	if(alumno==NULL){
		alumno = fopen("Alumnos.txt", "w+");
		cout<<"\n ARCHIVO CREADO INTENTE DE NUEVO";
		fclose(alumno);
		getch();
		return;
	}
	
		cout<<"\n-----------------------------------------------------"<<endl;	
		cout<<"\nIngrese el carnet del alumno: ";
	    cin>>auxcod;
	    cout<<"\n-----------------------------------------------------"<<endl;
	    
	    fread(&Alumno, sizeof(Alumno), 1,alumno);
	    while(!feof(alumno)){
	    	
	    	if(strcmp(Alumno.carnet, auxcod)==0){
	    		cout<<"\n YA EXISTE UN ALUMNO CON ESE CARNET";
	    		fclose(alumno);
	    		getch();
	    		return;
			}
			fread(&Alumno, sizeof(Alumno), 1,alumno);
		}
		
		strcpy(Alumno.carnet, auxcod);
		cout<<"\n Ingrese el nombre del alumno: ";
		cin>>Alumno.carnet;
			cout<<"\n-----------------------------------------------------"<<endl;	
			cout<<"\nIngrese el Codigo de la Carrera: ";
	        cin>>aux;
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
	        	fclose(alumno);
	        	fclose(carrera);
	        	getch();
	        	return;
		}
	     
			cout<<"\n Vuelva a escribir el curso para confirmar: ";
			cin>>Alumno.alumno_carrera; 
			
			cout<<"\n Registro Creado";
			fwrite(&Alumno, sizeof(Alumno), 1,alumno);
			fclose(alumno);
	        fclose(carrera);
			system("pause>nul");  	
}