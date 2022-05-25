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