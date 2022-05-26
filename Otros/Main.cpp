#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

void alumno(void);
void catedraticocontra(void);
void admincontra(void);
void User(void);

int main(){
	
	int opcion;
	bool x=true;
	
	do{
	system("cls");
	system("color 07");
	cout<<"\n------Seleccione el tipo de usario----"<<endl;
	cout<<"- Opcion 1: Alumno                   - ";
	cout<<"\n--------------------------------------"<<endl;
	cout<<"- Opcion 2: Administrador            - ";
	cout<<"\n--------------------------------------"<<endl;
	cout<<"- Opcion 3: Super Usuario            - ";
	cout<<"\n--------------------------------------"<<endl;
	cout<<"- Opcion 4: Catedratico              - ";
	cout<<"\n--------------------------------------"<<endl;
	cout<<"- Opcion 5: Salir                    - ";
	cout<<"\n------------------------------------- ";
	cout<<"\n\n Elija una Opcion: ";
	cin>>opcion;
	

	switch(opcion)
	{
		case 1:
			alumno();
		break;
		
		case 2:
			admincontra();
		break;
		
		case 3:
			User();
		break;
		
		case 4:
			catedraticocontra();
		break;
		
		case 5:
			x=false;
		break;
		
		default:
			cout<<"\n Opcion Incorrecta !!!POR FAVOR VERIFIQUE!!!!";
		break;
	}
	
	}while(x);
	return(0);
}