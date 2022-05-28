#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

void Tablas(void);
void alumno(void);

void usermenu(void){
	
	int x;
	bool rep=true;
	do{
	system("cls");
	system("color 07");
	cout<<"\n -----------------Menu de Opciones-------------------"<<endl;
	cout<<"- Opcion 1: Menu de tablas                           -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 2: Menu de evaluaciones                     -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 3: Menu de administracion                   -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 4: Regresar al Menu Principal           -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"\n\n Elija una Opcion: ";
	cin>>x;
	system("cls");
	switch(x){
		
		case 1:
			Tablas();
		break;
		
		case 2:
			alumno();
		break;
		
		case 3:
		
		break;
	
		case 4:
			rep=false;
		break;
		
		default:
			cout<<"\n OPCION INCORRECTA PORVAFOR VERIFIQUE!!!";
		break;
	}
	}while(rep);
}