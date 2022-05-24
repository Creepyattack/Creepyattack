#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

void carreras(void);
void cursos(void);

void admin(void){
	
	int x;
	bool rep=true;
	do{
	system("cls");
	system("color 07");
	cout<<"\n -----------------Menu de Opciones-------------------"<<endl;
	cout<<"- Opcion 1: Ingreso Archivo de Carreras              -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 2: Ingreso Archivo de cursos por carreras   -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 3: Ingreso Archivo de cursos por secciones  -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 4: Ingreso Archivo catedraticos             -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 5: Ingreso Archivo de alumnos               -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 6: Regresar al ingreso de usuario           -";
	cout<<"\n-----------------------------------------------------"<<endl;
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
			
		break;
		
		case 4:
			
		break;
		
		case 5:
			
		break;
		
		case 6:
			rep=false;
		break;
		
		default:
			cout<<"\n OPCION INCORRECTA PORVAFOR VERIFIQUE!!!";
		break;
	}
	}while(rep);
}