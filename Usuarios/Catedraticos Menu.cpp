#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

void reporteXCatedratico(void);

void catedraticosmenu(void){
	
	int x;
	bool rep=true;
	do{
	system("cls");
	system("color 07");
	cout<<"\n -----------------Menu de Opciones-------------------"<<endl;
	cout<<"- Opcion 1: Consultar sus propias evaluaciones       -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"- Opcion 2: Regresar al ingreso de usuario           -";
	cout<<"\n-----------------------------------------------------"<<endl;
	cout<<"\n\n Elija una Opcion: ";
	cin>>x;
	system("cls");
	switch(x){
		
		case 1:
			reporteXCatedratico();
		break;
		
		case 2:
			rep=false;
		break;
		
		default:
			cout<<"\n OPCION INCORRECTA PORVAFOR VERIFIQUE!!!";
		break;
	}
	}while(rep);
}