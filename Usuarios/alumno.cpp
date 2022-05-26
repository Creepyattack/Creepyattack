#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

void evaluacion(void);

void alumno(void){
	
	int x;
	bool rep=true;
	
	do{
		system("cls");
		
		cout<<"\n-----------Menu de Opciones----------- "<<endl;
		cout<<"- Opcion 1: Realizar el cuestonario  - ";
		cout<<"\n---------------------------------------"<<endl;
		cout<<"- Opcion 2: Salir                    - ";
		cout<<"\n-------------------------------------- ";
		cout<<"\n\n Elija una Opcion: ";
		cin>> x;
		
		system("cls");
		
		switch(x){
			
			case 1:
				evaluacion();
			break;
			
			case 2:
				rep=false;
			break;
			
			default:
				cout<<"\n OPCION INCORRECTA VERIFIQUE";
			break;
		}	
	}while(rep);
}