#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.hpp"

using namespace std;

void altasctdcursos(void);
void cambiosctd(void);
void bajasctd(void);

void catedraticos_cursos(void){
	
	int i;
	bool repetir=true;
	
	do
	{
	system("cls");
	
	cout<<"\n -----Menu de Opciones de Catedraticos por cursos----"<<endl;
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
			altasctdcursos();
		break;
		
		case 2:	
			bajasctd();
		break;
		
		case 3:
			cambiosctd();
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

void altasctdcursos(void){
	
	FILE *catedraticos;
	FILE *secciones;
	FILE *ctdcursos;
	
	struct tipo_catedraticos Catedraticos;
	struct tipo_seccion Seccion;
	struct tipo_catedraticos_cursos Ctd;
	
	bool z=false;
	bool c=false;
	
	char auxcod[50],aux[50];
	
	cout<<"\n REGISTRO DE CATEDRATICOS POR CURSOS";
	
	catedraticos=fopen("Catedrativos.txt","r+");
	secciones = fopen("Secciones.txt","r+");
	ctdcursos =fopen("Catedraticos_cursos.txt", "r+");
	
	if(ctdcursos==NULL){
		
		ctdcursos =fopen("Catedraticos_cursos.txt", "w+");
		cout<<"\n ARCHIVO CREADO INTENTE DE NUEVO";
		fclose(ctdcursos);
		fclose(secciones);
		fclose(catedraticos);
		getch();
		return;
	}
	
		cout<<"\n-----------------------------------------------------"<<endl;	
		cout<<"\n Ingrese el Codigo de la seccion: ";
		cin>>auxcod;
		cout<<"\n-----------------------------------------------------"<<endl;

		
		fread(&Seccion, sizeof(Seccion), 1,secciones);
			while(!feof(secciones)){
				
				if(strcmp(Seccion.seccion, auxcod)==0){
					cout<<"\n La seccion es: "<<Seccion.seccion;
					cout<<"\n El curso es : "<<Seccion.nombre_seccion<<endl;
					getch();
	        		z = true;
	        		strcpy(Ctd.seccioncat, auxcod);
				}
				fread(&Seccion, sizeof(Seccion), 1,secciones);
			}
			
			if(z=false){
				cout<<"\n ERROR, no existe una seccion con ese codigo"<<endl;
	        	fclose(ctdcursos);
				fclose(secciones);
				fclose(catedraticos);
	        	getch();
	        	return;
			}
			cout<<"\n Vuelva a escribir el curso para confirmar: ";
			cin>>Ctd.nombre_curso_seccion;
			
			
				
			cout<<"\n-----------------------------------------------------"<<endl;	
			cout<<"\n Ingrese el Codigo del Catedratico: ";
			cin>>aux;
			cout<<"\n-----------------------------------------------------"<<endl;
			
			fread(&Catedraticos, sizeof(Catedraticos), 1,catedraticos);
				while(!feof(catedraticos)){
					if(strcmp(Catedraticos.codigo_catedratico, aux)==0){
						cout<<"\n El codigo del catedratico es: "<<Catedraticos.codigo_catedratico;
						cout<<"\n El Nombre del catedratico es: "<<Catedraticos.nombre<<endl;
						cout<<"\n El titulo del catedratico es: "<<Catedraticos.titulo;
						getch();
		        		c = true;
					}
					fread(&Catedraticos, sizeof(Catedraticos), 1,catedraticos);
				}
					if(c=false){
					cout<<"\n ERROR, no existe un catedratico con ese codigo"<<endl;
		        	fclose(ctdcursos);
					fclose(secciones);
					fclose(catedraticos);
		        	getch();
		        	return;
					}
					
				strcpy(Ctd.codigo_CAT, aux);
				cout<<"\n Vuelva a escribir el nombre del catedratico para confirmar: ";
				cin>>Ctd.nombre_cat;
				cout<<"\n Vuelva a escribir el titulo del catedratico para confirmar: ";
				cin>>Ctd.titulo_cat;
				cout<<"\n Registro Creado";
				fwrite(&Ctd, sizeof(Ctd), 1,ctdcursos);
					fclose(ctdcursos);
					fclose(secciones);
					fclose(catedraticos);
				system("pause>nul");
}

void bajasctd(void){
	
	FILE *ctdcursos;
	struct tipo_catedraticos_cursos Ctd;
	char aux[50], op;
	ctdcursos =fopen("Catedraticos_cursos.txt", "r+");
	
	if(ctdcursos==NULL){
		cout<<"\n NO EXISTE EL ARCHIVO";
		fclose(ctdcursos);
		getch();
		return;
	}
	
	cout<<"\n Ingrese la seccion  y curso que desea eliminar: ";
	cin>>aux;
	
	fread(&Ctd, sizeof(Ctd), 1,ctdcursos);
		while(!feof(ctdcursos)){
			if(strcmp(Ctd.seccioncat, aux)==0){
				cout<<"\n-----------------------------------"<<endl;
	    		cout<<"\n carrera, curso y seccion: "<<Ctd.seccioncat<<endl;
	    		cout<<" Nombre del curso: "<<Ctd.nombre_curso_seccion<<endl;
	    		cout<<" Codigo del Catedratico: "<<Ctd.codigo_CAT<<endl;
	    		cout<<" Nombre del catedratico: "<<Ctd.nombre_cat<<endl;
	    		cout<<" Titulo del catedratico: "<<Ctd.titulo_cat<<endl;
	    		cout<<"\n-----------------------------------"<<endl;
	    		
	    		strcpy(Ctd.seccioncat, "----");
	    		strcpy(Ctd.nombre_curso_seccion, "----");
	    		strcpy(Ctd.codigo_CAT, "----");
	    		strcpy(Ctd.nombre_cat, "----");
	    		strcpy(Ctd.titulo_cat, "----");
	    		
	    		do{
	    		cout<<"\n\nDesea eliminar el Registro? [S/N]: ";
				cin>>op;	
				op=toupper(op);
				}while(op!='S' && op!='N');
					
				if(op == 'S')
				{
					fseek(ctdcursos, ftell(ctdcursos)-sizeof(Ctd), SEEK_SET);
					fwrite(&Ctd, sizeof(Ctd), 1,ctdcursos);
					cout<<"\n REGISTRO ELIMINADO!!!";
				}
				fclose(ctdcursos);
				getch();
				return;		
			}
			fread(&Ctd, sizeof(Ctd), 1,ctdcursos);
		}
		cout<<"\nNO SE ENCUENTRA EL REGISTRO";
		fclose(ctdcursos);
		getch();
		return;
}

void cambiosctd(void){
	
	FILE *ctdcursos;
	bool rep=true;
	struct tipo_catedraticos_cursos Ctd;
	char aux[50];
	int op;
	ctdcursos =fopen("Catedraticos_cursos.txt", "r+");
	
	if(ctdcursos==NULL){
		cout<<"\n NO EXISTE EL ARCHIVO";
		fclose(ctdcursos);
		getch();
		return;
	}
	
	cout<<"\n Ingrese la seccion  y curso que desea eliminar: ";
	cin>>aux;
	
	fread(&Ctd, sizeof(Ctd), 1,ctdcursos);
		while(!feof(ctdcursos)){
			if(strcmp(Ctd.seccioncat, aux)==0){
				cout<<"\nLos Datos de la seccion son: ";
				cout<<"\n-----------------------------------"<<endl;
	    		cout<<"\n carrera, curso y seccion: "<<Ctd.seccioncat<<endl;
	    		cout<<" Nombre del curso: "<<Ctd.nombre_curso_seccion<<endl;
	    		cout<<" Codigo del Catedratico: "<<Ctd.codigo_CAT<<endl;
	    		cout<<" Nombre del catedratico: "<<Ctd.nombre_cat<<endl;
	    		cout<<" Titulo del catedratico: "<<Ctd.titulo_cat<<endl;
	    		cout<<"\n-----------------------------------"<<endl;
	    		cout<<"\n\n\n\r";
	    		
	    		system("pause");
				system("cls");
					
						do{
				
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Que desea cambiar:              -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Cambiar codigo del catedratico: Opcion 1.-";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Cambiar Nombre del catedratico: Opcion 2.-";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Cambiar titulo del catedratico: Opcion 3.-";
							cout<<"\n---------------------------------"<<endl;
							cout<<"- Terminar o Cancelar: Opcion 0.  -";
							cout<<"\n---------------------------------"<<endl;
							cout<<"\n\n Elija una Opcion: ";
							cin>>op;
							
							switch(op)
							{
								case 1:
									system("cls");
									
									cout<<"\nIngrese el nuevo codigo del catedratico: ";
									cin>>Ctd.codigo_CAT;
									system("cls");
								break;
								
								case 2:
									system("cls");
									
									cout<<"\nIngrese el nuevo Nombre del catedratico: ";
									cin>>Ctd.nombre_cat;
									system("cls");
								break;
								
								case 3:
									system("cls");
									
									cout<<"\nIngrese el nuevo Titulo del catedratico: ";
									cin>>Ctd.titulo_cat;
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
							
							fseek(ctdcursos, ftell(ctdcursos)-sizeof(Ctd), SEEK_SET);
							fwrite(&Ctd, sizeof(Ctd), 1,ctdcursos);
							
								fclose(ctdcursos);
								cout<<"\n\n EL REGISTRO HA SIDO MODIFICADO";
								getch();
								return;	
							}
							fread(&Ctd, sizeof(Ctd), 1,ctdcursos);
						}
						cout<<"\nNO SE ENCONTRO LA SECCION CON ESE CODIGO!!!";
						fclose(ctdcursos);
						getch();
						return;
}