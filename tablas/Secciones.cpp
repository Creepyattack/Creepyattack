#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.hpp"

using namespace std;

void altassecciones(void);
void bajassecciones(void);
void cambiosseccion(void);

void secciones(void){
	
	int i;
	bool repetir=true;
	
	do
	{
	system("cls");
	
	cout<<"\n -----------Menu de Opciones de Secciones------------"<<endl;
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
			altassecciones();
		break;
		
		case 2:	
			bajassecciones();
		break;
		
		case 3:
			cambiosseccion();
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

void altassecciones(void){
	
	bool encontrado = false;
	FILE *secciones;
	FILE *cursos;
	struct tipo_seccion Seccion;
	struct tipo_cursos Cursos;
	char auxcod[10],aux[50],auxnom[50];
	
	cout<<"\n\r RESGISTRO DE SECCIONES";
	
	secciones = fopen("Secciones.txt","r+");
	cursos = fopen("Cursos.txt","r+");
	
	if(secciones==NULL){
		
		secciones = fopen("Secciones.txt","w+");
		cout<<"\n ARCHIVO CREADO INTENTE DE NUEVO";
		fclose(cursos);
		fclose(secciones);
		getch();
		return;
	}
	
		cout<<"\n-----------------------------------------------------"<<endl;	
		cout<<"\nIngrese el Codigo del Curso: ";
	    cin>>auxcod;
	    cout<<"\n-----------------------------------------------------"<<endl;
	    
	    fread(&Cursos, sizeof(Cursos), 1,cursos);
	        
	        while(!feof(cursos)){
	        	
				if(strcmp(Cursos.cod_curso, auxcod)== 0){
					cout<<"\n El curso es : "<<Cursos.nombre_curso<<endl;
	        		getch();
	        		encontrado = true;
				}
				fread(&Cursos, sizeof(Cursos), 1,cursos);
			}
		if(encontrado== false){
				cout<<"\n ERROR, no existe un curso con esa clave"<<endl;
	        	fclose(cursos);
	        	fclose(secciones);
	        	getch();
	        	return;
		}
			cout<<"\n Vuelva a escribir el curso para confirmar: ";
			cin>>Seccion.nombre_seccion;
			cout<<"\n La seccion que quiere crear con el curso: ";
			cin>>aux;
		fread(&Seccion, sizeof(Seccion), 1,secciones);
			while(!feof(secciones)){
				if(strcmp(Seccion.seccion, aux)==0){
					
					cout<<"\n YA EXISTE ESA SECCION";
					fclose(cursos);
		        	fclose(secciones);
		        	getch();
		        	return;
				}
				fread(&Seccion, sizeof(Seccion), 1,secciones);
			}
			strcpy(Seccion.seccion, aux);
			cout<<"\n Registro Creado";
			fwrite(&Seccion, sizeof(Seccion), 1,secciones);
			fclose(cursos);
	        fclose(secciones);
			system("pause>nul");
}

void bajassecciones(void){
	
		char aux[10], op;
		FILE *secciones;
		struct tipo_seccion Seccion;
		
		secciones = fopen("Secciones.txt","r+");
		if(secciones==NULL){
			cout<<"\n NO EXISTE EL ARCHIVO";
			fclose(secciones);
			getch();
			return;
		}
		
		cout<<"\n Ingrese la seccion que desea eliminar: ";
		cin>>aux;
		
		fread(&Seccion, sizeof(Seccion), 1,secciones);
		while(!feof(secciones)){
		    if(strcmp(Seccion.seccion, aux)==0)
			{
				cout<<"\n-----------------------------------"<<endl;
				cout<<"\n Seccion del curso: "<<Seccion.seccion<<endl;
				cout<<" Nombre del curso: "<<Seccion.nombre_seccion<<endl;
				cout<<"\n-----------------------------------"<<endl;
				
				strcpy(Seccion.seccion, "-------");
				strcpy(Seccion.nombre_seccion, "--------");
				
				do{
				  cout<<"\n\nDesea eliminar el Registro? [S/N]: ";
				cin>>op;	
				op=toupper(op);
				}while(op!='S' && op!='N');
				
				if(op == 'S')
				{
					fseek(secciones, ftell(secciones)-sizeof(Seccion), SEEK_SET);
					fwrite(&Seccion, sizeof(Seccion), 1,secciones);
					cout<<"\n REGISTRO ELIMINADO!!!";
				}		
				fclose(secciones);
				getch();
				return;
			}
			fread(&Seccion, sizeof(Seccion), 1,secciones);
		}
		cout<<"\nNO SE ENCUENTRA EL REGISTRO";
		fclose(secciones);
		getch();
		return;	
}

void cambiosseccion(void){
	
	FILE *secciones;
		struct tipo_seccion Seccion;
		bool rep = true;
		char aux[5];
		int op;
		
		cout<<"\n\r CAMBIOS A LOS REGISTROS DE LAS SECCIONES";
	
		secciones = fopen("Secciones.txt","r+");
		if(secciones==NULL){
			cout<<"\n NO EXISTE EL ARCHIVO";
			fclose(secciones);
			getch();
			return;
		}
		
			cout<<"\nIngrese la seccion del curso que desea modificar: ";
			cin>>aux;
			
			fread(&Seccion, sizeof(Seccion), 1,secciones);
			while(!feof(secciones)){
			    if(strcmp(Seccion.seccion, aux)==0)
				{
						cout<<"\nLos Datos de la seccion son: ";
						cout<<"\n-----------------------------------"<<endl;
						cout<<"\n Seccion del curso: "<<Seccion.seccion<<endl;
						cout<<" Nombre del curso: "<<Seccion.nombre_seccion<<endl;
						cout<<"\n-----------------------------------"<<endl;

					
					cout<<"\n\n\n\r";
			
					system("pause");
					system("cls");
					
						do{
				
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Que desea cambiar:              -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Cambiar seccion: Opcion 1.       -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Terminar o Cancelar: Opcion 0.  -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"\n\n Elija una Opcion: ";
							cin>>op;
							
							switch(op)
							{
								case 1:
									system("cls");
									
									cout<<"\nIngrese la nueva seccion del curso: ";
									cin>>Seccion.seccion;
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
							
							fseek(secciones, ftell(secciones)-sizeof(Seccion), SEEK_SET);
							fwrite(&Seccion, sizeof(Seccion), 1,secciones);
							
								fclose(secciones);
								cout<<"\n\n EL REGISTRO HA SIDO MODIFICADO";
								getch();
								return;	
							}
							fread(&Seccion, sizeof(Seccion), 1,secciones);;
						}
						cout<<"\nNO SE ENCONTRO EL PRODUCTOS CON ESE CODIGO!!!";
						fclose(secciones);
						getch();
						return;
}

