#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

void evaluacion(void);
void Password(void);

int main(){
	
	int opcion;
	bool x=true;
	
	do{
	system("cls");
	system("color 07");
	cout<<"\n--------------Menu de Inicio----------"<<endl;
	cout<<"- Opcion 1: Realizar la evaluacion   - ";
	cout<<"\n--------------------------------------"<<endl;
	cout<<"- Opcion 2: Entrar al sistema        - ";
	cout<<"\n--------------------------------------"<<endl;
	cout<<"- Opcion 3: Salir                    - ";
	cout<<"\n------------------------------------- ";
	cout<<"\n\n Elija una Opcion: ";
	cin>>opcion;
	

	switch(opcion)
	{
		case 1:
			evaluacion();
		break;
		
		case 2:
			Password();
		break;
	
		case 3:
			x=false;
		break;
		
		default:
			cout<<"\n Opcion Incorrecta !!!POR FAVOR VERIFIQUE!!!!";
		break;
	}
	
	}while(x);
	return(0);
}