#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

void usermenu(void){
	
	int x;
	bool rep=true;
	do{
	system("cls");
	system("color 07");
	cout<<"\n -----------------Menu de Opciones-------------------"<<endl;
	cout<<"- Opcion 1: Realizar el Cuestonario                  -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 2: Ingreso Archivo de Carreras              -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 3: Ingreso Archivo de cursos por carreras   -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 4: Ingreso Archivo de cursos por secciones  -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 5: Ingreso Archivo catedraticos             -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 6: Ingreso Archivo de alumnos               -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 7: Regresar al ingreso de usuario           -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"\n\n Elija una Opcion: ";
	cin>>x;
	system("cls");
	switch(x){
		
		case 1:
			
		break;
		
		case 2:
			
		break;
		
		case 3:
			
		break;
		
		case 4:
			
		break;
		
		case 5:
			
		break;
		
		case 6:
			
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