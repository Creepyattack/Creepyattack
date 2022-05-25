#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.hpp"

using namespace std;

void altasalumnos(void);
void bajasalumnos(void);

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
			altasalumnos();
		break;
		
		case 2:	
			bajasalumnos();
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

void altasalumnos(void){
	
	bool encontrado = false;
	FILE *alumno;
	FILE *carrera;
	char auxcod[50],aux[10];
	struct tipo_alumno Alumno;
	struct tipo_carrera  Carrera;
	
	cout<<"\n\r REGISTRO DE ALUMNOS";
	alumno = fopen("Alumnos.txt", "r+");
	
	if(alumno==NULL){
		alumno = fopen("Alumnos.txt", "w+");
		cout<<"\n ARCHIVO CREADO INTENTE DE NUEVO";
		fclose(alumno);
		getch();
		return;
	}
	
		cout<<"\n-----------------------------------------------------"<<endl;	
		cout<<"\nIngrese el carnet del alumno: ";
	    cin>>auxcod;
	    cout<<"\n-----------------------------------------------------"<<endl;
	    
	    fread(&Alumno, sizeof(Alumno), 1,alumno);
	    while(!feof(alumno)){
	    	
	    	if(strcmp(Alumno.carnet, auxcod)==0){
	    		cout<<"\n YA EXISTE UN ALUMNO CON ESE CARNET";
	    		fclose(alumno);
	    		getch();
	    		return;
			}
			fread(&Alumno, sizeof(Alumno), 1,alumno);
		}
		
		strcpy(Alumno.carnet, auxcod);
		cout<<"\n Ingrese el nombre del alumno: ";
		cin>>Alumno.carnet;
			cout<<"\n-----------------------------------------------------"<<endl;	
			cout<<"\nIngrese el Codigo de la Carrera: ";
	        cin>>aux;
	        cout<<"\n-----------------------------------------------------"<<endl;
	        
	        fread(&Carrera, sizeof(Carrera), 1,carrera);
	        
	        while(!feof(carrera)){
	        	
				if(strcmp(Carrera.cod_carrera, auxcod)== 0){
					cout<<"\n La carrera es : "<<Carrera.carrera<<endl;
	        		getch();
	        		encontrado = true;
				}
				fread(&Carrera, sizeof(Carrera), 1,carrera);
			}
		if(encontrado== false){
				cout<<"\n ERROR, no existe una carrera con esa clave"<<endl;
	        	fclose(alumno);
	        	fclose(carrera);
	        	getch();
	        	return;
		}
	     
			cout<<"\n Vuelva a escribir el curso para confirmar: ";
			cin>>Alumno.alumno_carrera; 
			
			cout<<"\n Registro Creado";
			fwrite(&Alumno, sizeof(Alumno), 1,alumno);
			fclose(alumno);
	        fclose(carrera);
			system("pause>nul");  	
}

void bajasalumnos(void){
	
	FILE *alumno;
	char auxcod[50],op;
	
	struct tipo_alumno Alumno;
	cout<<"\n\r BAJAS DE LOS ALUMNOS";
	
	alumno = fopen("Alumnos.txt", "r+");
	
	if(alumno==NULL){
		cout<<"\n NO EXISTE EL ARCHIVO";
		fclose(alumno);
		getch();
		return;
	}
	
	cout<<"\n Ingrese el carnet del alumno que desea eliminar: ";
	cin>>auxcod;
	
		fread(&Alumno, sizeof(Alumno), 1,alumno);
	    while(!feof(alumno)){
	    	
	    	if(strcmp(Alumno.carnet, auxcod)==0){
	    		
	    		cout<<"\n-----------------------------------"<<endl;
	    		cout<<"\n Carnet del alumno: "<<Alumno.carnet<<endl;
	    		cout<<" Nombre del alumno: "<<Alumno.nombre_alumno<<endl;
	    		cout<<" Carrera del alumno: "<<Alumno.alumno_carrera<<endl;
	    		cout<<"\n-----------------------------------"<<endl;
	    		
	    		strcpy(Alumno.carnet, "----");
	    		strcpy(Alumno.nombre_alumno, "----");
	    		strcpy(Alumno.alumno_carrera, "----");
	    		
	    		do{
	    		cout<<"\n\nDesea eliminar el Registro? [S/N]: ";
				cin>>op;	
				op=toupper(op);
				}while(op!='S' && op!='N');
				
					if(op == 'S')
				{
					fseek(alumno, ftell(alumno)-sizeof(Alumno), SEEK_SET);
					fwrite(&Alumno, sizeof(Alumno), 1,alumno);
					cout<<"\n REGISTRO ELIMINADO!!!";
				}		
				fclose(alumno);
				getch();
				return;
			}
			fread(&Alumno, sizeof(Alumno), 1,alumno);
		}
		cout<<"\nNO SE ENCUENTRA EL REGISTRO";
		fclose(alumno);
		getch();
		return;	
}

void cambiosalumno(void){
	
	
	FILE *alumno;
	char auxcod[50];
	bool rep = true;
	int op;
	
	struct tipo_alumno Alumno;
	cout<<"\n\r CAMBIOS A LOS REGISTROS DE LOS ALUMNOS";
	
	alumno = fopen("Alumnos.txt", "r+");
	
	if(alumno==NULL){
		cout<<"\n NO EXISTE EL ARCHIVO";
		fclose(alumno);
		getch();
		return;
	}
	
		cout<<"\n Ingrese el carnet del alumno que desea modificar: ";
		cin>>auxcod;
		
		fread(&Alumno, sizeof(Alumno), 1,alumno);
	    while(!feof(alumno)){
	    	if(strcmp(Alumno.carnet, auxcod)==0){
	    		
	    			cout<<"\nLos Datos del alumno son: ";
					cout<<"\n-----------------------------------"<<endl;
					cout<<"\n Carnet del alumno: "<<Alumno.carnet<<endl;
		    		cout<<" Nombre del alumno: "<<Alumno.nombre_alumno<<endl;
		    		cout<<" Carrera del alumno: "<<Alumno.alumno_carrera<<endl;
		    		cout<<"\n-----------------------------------"<<endl;
		    		cout<<"\n\n\n\r";
			
					system("pause");
					system("cls");
					
						do{
				
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Que desea cambiar:              -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Cambiar Nombre: Opcion 1.       -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Cambiar Carrera: Opcion 2.      -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Terminar o Cancelar: Opcion 0.  -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"\n\n Elija una Opcion: ";
							cin>>op;
							
							switch(op)
							{
								case 1:
									system("cls");
									
									cout<<"\nIngrese el Nuevo Nombre del Alumno: ";
									cin>>Alumno.nombre_alumno;
									system("cls");
								break;
								
								case 2:
									system("cls");
									cout<<"\nIngrese la Nueva carrera del Alumno: ";
									cin>>Alumno.alumno_carrera;
									system("cls");
								break;

								case 0:
									rep = false;
								break;
								
								default:
									cout<<"\n Opcion Incorrecta";
								break;
							}
							}while(rep);
							
							fseek(alumno, ftell(alumno)-sizeof(Alumno), SEEK_SET);
							fwrite(&Alumno, sizeof(Alumno), 1,alumno);
							
							fclose(alumno);
							cout<<"\n\n EL REGISTRO HA SIDO MODIFICADO";
								getch();
								return;	
							}
							fread(&Alumno, sizeof(Alumno), 1,alumno);
						}
						cout<<"\nNO SE ENCONTRO EL PRODUCTOS CON ESE CODIGO!!!";
						fclose(alumno);
						getch();
						return;	
}