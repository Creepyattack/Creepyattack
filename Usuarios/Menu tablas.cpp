#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string>

using namespace std;

void catedraticos_cursos(void);
void secciones(void);
void carreras(void);
void cursos(void);
void catedraticos(void);
void alumnos(void);

void Tablas(void){
	
	int x;
	bool rep=true;
	do{
	system("cls");
	system("color 07");
	cout<<"\n ------------Menu de Opciones de las tablas--------------------"<<endl;
	cout<<"- Opcion 1: Ingreso Archivo de Carreras                        -";
	cout<<"\n---------------------------------------------------------------"<<endl;
	cout<<"- Opcion 2: Ingreso Archivo de cursos por carreras             -";
	cout<<"\n---------------------------------------------------------------"<<endl;
	cout<<"- Opcion 3: Ingreso Archivo de cursos por secciones            -";
	cout<<"\n---------------------------------------------------------------"<<endl;
	cout<<"- Opcion 4: Ingreso Archivo catedraticos                       -";
	cout<<"\n---------------------------------------------------------------"<<endl;
	cout<<"- Opcion 5: Ingreso Archivo de alumnos                         -";
	cout<<"\n---------------------------------------------------------------"<<endl;
	cout<<"- Opcion 6: Ingreso Archivo de catedraticos por curso y seccion-";
	cout<<"\n---------------------------------------------------------------"<<endl;
	cout<<"- Opcion 7: Regresar al Menu anterior                          -";
	cout<<"\n---------------------------------------------------------------"<<endl;
	cout<<"\n\n Elija una Opcion: ";
	cin>>x;
	system("cls");
	switch(x){
		
		case 1:
			carreras();
		break;
		
		case 2:
			cursos();
		break;
		
		case 3:
			secciones();
		break;
		
		case 4:
			catedraticos();
		break;
		
		case 5:
			alumnos();
		break;
		
		case 6:
			catedraticos_cursos();
		break;
		
		case 7:
			rep=false;
		break;
		
		default:
			cout<<"\n OPCION INCORRECTA PORVAFOR VERIFIQUE!!!";
		break;
	}
	}while(rep);
}