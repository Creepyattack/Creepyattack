#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.hpp"


using namespace std;

void altascursos(void);
void bajascursos(void);
void cambioscursos(void);

void cursos(void){
	int i;
	bool repetir=true;
	
	do
	{
	system("cls");
	
	cout<<"\n -----------Menu de Opciones de Cursos---------------"<<endl;
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
			altascursos();
		break;
		
		case 2:	
			bajascursos();
		break;
		
		case 3:
			cambioscursos();
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

void altascursos(void){

	bool encontrado = false;
	FILE *carrera;
	FILE *cursos;
	
	char aux[50];
	char auxcod[10];
	
	struct tipo_carrera  Carrera;
	struct tipo_cursos Cursos;
	
	cout<<"\n\r REGISTRO DE CURSOS";
	
	cursos = fopen("Cursos.txt","r+");
	carrera = fopen("Carreras.txt","r+");
	
	if(cursos==NULL){
		
		cursos = fopen("Cursos.txt","w");
		cout<<"\n ARCHIVO CREADO INTENTE DE NUEVO";
		fclose(cursos);
		fclose(carrera);
		getch();
		return;
	}
	
		cout<<"\n-----------------------------------------------------"<<endl;	
		cout<<"\nIngrese el Codigo de la Carrera: ";
	    cin>>auxcod;
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
	        	fclose(cursos);
	        	fclose(carrera);
	        	getch();
	        	return;
		}
		
		strcpy(Carrera.cod_carrera, auxcod);
		
		cout<<"\n-----------------------------------------------------"<<endl;	
		cout<<"\nIngrese el Codigo del curso: ";
	    cin>>aux;
	    cout<<"\n-----------------------------------------------------"<<endl;
	    
	    fread(&Cursos, sizeof(Cursos), 1,cursos);
	    
	    	while(!feof(cursos)){
	    		
	    		if(strcmp(Cursos.cod_curso, aux)== 0){
	    			cout<<"\n ERROR, ya existe un curso con esa clave"<<endl;
	        		fclose(cursos);
	        		fclose(carrera);
	        		getch();
	        		return;
				}
				fread(&Cursos, sizeof(Cursos), 1,cursos);
			}
			
			strcpy(Cursos.cod_curso, aux);
			cout<<"\n Ingrese el nombre del curso: ";
			cin>>Cursos.nombre_curso;
			cout<<"\n Ingrese el ciclo del curso: ";
			cin>>Cursos.ciclo;
			cout<<"\n Registro Creado";
			fwrite(&Cursos, sizeof(Cursos), 1,cursos);
			fclose(cursos);
			fclose(carrera);
			system("pause>nul");
}

void bajascursos(void){
	
		char auxcod[10], op;
		FILE *cursos;
		struct tipo_cursos Cursos;
		
		cursos = fopen("Cursos.txt","r+");
		if(cursos == NULL){
			cout<<"\nNO EXISTE EL ARCHIVO !!!";
			fclose(cursos);
			getch();
			return;
		}
		
		cout<<"\n Ingrese la clave de la carrera que desea Eliminar: ";
		cin>>auxcod;
		
		fread(&Cursos, sizeof(Cursos), 1,cursos);
		while(!feof(cursos)){
		   	if(strcmp(Cursos.cod_curso, auxcod)== 0)
			{
				cout<<"\n-----------------------------------"<<endl;
				cout<<"\n Clave de la carrera: "<<Cursos.carrera_curso<<endl;
				cout<<" Codigo del Curso: "<<Cursos.cod_curso<<endl;
				cout<<" Nombre del Curso: "<<Cursos.nombre_curso<<endl;
				cout<<" Ciclo del Curso: "<<Cursos.ciclo<<endl;
				cout<<"\n-----------------------------------"<<endl;
				
				strcpy(Cursos.carrera_curso, "----");
				strcpy(Cursos.cod_curso, "----");
				strcpy(Cursos.nombre_curso, "----");
				Cursos.ciclo=0;
				
				do{
				  cout<<"\n\nDesea eliminar el Registro? [S/N]: ";
				cin>>op;	
				op=toupper(op);
				}while(op!='S' && op!='N');
				
				if(op == 'S')
				{
					fseek(cursos, ftell(cursos)-sizeof(Cursos), SEEK_SET);
					fwrite(&Cursos, sizeof(Cursos), 1,cursos);
					cout<<"\n REGISTRO ELIMINADO!!!";
				}		
				fclose(cursos);
				getch();
				return;
			}
			fread(&Cursos, sizeof(Cursos), 1,cursos);
		}
		cout<<"\nNO SE ENCUENTRA EL REGISTRO";
		fclose(cursos);
		getch();
		return;	
}

void cambioscursos(void){
	
		FILE *cursos;
		struct tipo_cursos Cursos;
		bool rep = true;
		char auxcod[5];
		int op;
		
		cout<<"\n\r CAMBIOS A LOS REGISTROS DE los Cursos";
	
		cursos = fopen("Cursos.txt","r+");
		
		if(cursos==NULL){
			
			cout<<"\n NO EXISTE EL ARCHIVO";
			fclose(cursos);
			getch();
			return;
		}
		
			cout<<"\nIngrese la clave del curso que desea modificar: ";
			cin>>auxcod;
			
			fread(&Cursos, sizeof(Cursos), 1,cursos);
			while(!feof(cursos)){
			    if(strcmp(Cursos.cod_curso, auxcod)== 0)
				{
						cout<<"\nLos Datos del curso son: ";
						cout<<"\n-----------------------------------"<<endl;
						cout<<"\n Clave de la carrera: "<<Cursos.carrera_curso<<endl;
						cout<<" Codigo del Curso: "<<Cursos.cod_curso<<endl;
						cout<<" Nombre del Curso: "<<Cursos.nombre_curso<<endl;
						cout<<" Ciclo del Curso: "<<Cursos.ciclo<<endl;
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
							cout<<"- Cambiar ciclo: Opcion 2.       -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Terminar o Cancelar: Opcion 0.  -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"\n\n Elija una Opcion: ";
							cin>>op;
							
							switch(op)
							{
								case 1:
									system("cls");
									
									cout<<"\nIngrese el Nuevo Nombre del curso: ";
									cin>>Cursos.nombre_curso;
									system("cls");
								break;
								
								case 2:
									system("cls");
									
									cout<<"\nIngrese el Nuevo Ciclo del curso: ";
									cin>>Cursos.ciclo;
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
							
							fseek(cursos, ftell(cursos)-sizeof(Cursos), SEEK_SET);
							fwrite(&Cursos, sizeof(Cursos), 1,cursos);
							
								fclose(cursos);
								cout<<"\n\n EL REGISTRO HA SIDO MODIFICADO";
								getch();
								return;	
							}
							fread(&Cursos, sizeof(Cursos), 1,cursos);
						}
						cout<<"\nNO SE ENCONTRO EL CURSO CON ESA CLAVE!!!";
						fclose(cursos);
						getch();
						return;
}
