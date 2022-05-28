#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

void reporteXalumnos(void);

void admin(void){
	
	int x;
	bool rep=true;
	do{
	system("cls");
	system("color 07");
	cout<<"\n --------------------------Menu de Opciones--------------------"<<endl;
	cout<<"- Opcion 1: Reporte de los alumnos que realizaron la evaluacion-";
	cout<<"\n---------------------------------------------------------------"<<endl;
	cout<<"- Opcion 2: Reporte del Catedratico evaluado                   -";
	cout<<"\n---------------------------------------------------------------"<<endl;
	cout<<"- Opcion 3: Regresar al Menu Principal                         -";
	cout<<"\n---------------------------------------------------------------"<<endl;
	cout<<"\n\n Elija una Opcion: ";
	cin>>x;
	system("cls");
	switch(x){
		
		case 1:
			reporteXalumnos();
		break;
		
		case 2:
			
		break;
		
		case 3:
			rep=false;
		break;
		
		default:
			cout<<"\n OPCION INCORRECTA PORVAFOR VERIFIQUE!!!";
		break;
	}
	}while(rep);
}