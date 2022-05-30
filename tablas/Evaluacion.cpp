#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.hpp"

using namespace std;

void evaluacion(void){
	
	system("cls");
	bool w=false;
	bool encontrado=false;
	bool encontra=false;
	
	FILE *prueba1;
	
	FILE *ctdcursos;
	FILE *alumno;
	FILE *carrera;
	
	char auxcod[50],auxnom[50],auxcar[50];
	
	struct tipo_evaluacion Eva1;
	
	struct tipo_alumno Alumno;
	struct tipo_catedraticos_cursos Ctd;
	struct tipo_carrera  Carrera;
	
	prueba1 =fopen("Prueba1.txt","r+");
	
	ctdcursos =fopen("Catedraticos_cursos.txt", "r+");
	alumno = fopen("Alumnos.txt", "r+");
	carrera = fopen("Carreras.txt","r+");
	
	if(prueba1==NULL){
		prueba1 =fopen("Prueba1.txt","w+");
	
		cout<<"\n SE A CREADO EL ARCHIVO DE LAS EVALUACIONES";
		fclose(prueba1);
		fclose(carrera);
		fclose(alumno);
		fclose(ctdcursos);
		getch();
		return;
	}
	
	cout<<"\t\t EVALUACION DE ESTUDIATES A DOCENTES";
	cout<<"\n-------------------------------------------------------------------------------";
	cout<<"\n - Carrera:  ";
	cin>>auxcod;
	
		fread(&Carrera, sizeof(Carrera), 1,carrera);
	        
	        while(!feof(carrera)){
	        	
	        	if(strcmp(Carrera.carrera, auxcod)== 0){
	        		w=true;	
				
				 }
	    	fread(&Carrera, sizeof(Carrera), 1,carrera);
	    }
	    
	    if(w==false){
	    		cout<<"\n ERROR, no existe la carrera con ese nombre"<<endl;
	        		fclose(prueba1);
					fclose(carrera);
					fclose(alumno);
					fclose(ctdcursos);
	        		getch();
	        		return;
		}
	        		
	        	cout<<"\n - Carnet del alumno: ";
				cin>>auxnom;
				
				fread(&Alumno, sizeof(Alumno), 1,alumno);
				    while(!feof(alumno)){
				    	
				    	if(strcmp(Alumno.carnet, auxnom)==0){
				    		encontrado=true;
				    		cout<<"\n - Nombre del Estudiante: "<<Alumno.nombre_alumno<<endl;
				    		cout<<"\n - Ciclo: "<<Alumno.ciclo_alumno<<endl;
				    	}
				    	fread(&Alumno, sizeof(Alumno), 1,alumno);
					}
				if(encontrado==false){
					cout<<"\n\n NO EXSITE EL ALUMNO CON ESE CARNET";
					fclose(prueba1);
					fclose(carrera);
					fclose(alumno);
					fclose(ctdcursos);
					getch();
					return;
				}
				
				fread(&Eva1, sizeof(Eva1), 1,prueba1);
					while(!feof(prueba1)){
						if(strcmp(Eva1.carnetalum, auxnom)==0){
							cout<<"\n\n ESTE ALUMNO YA HIZO LA EVALUACION";
							fclose(prueba1);
							fclose(carrera);
							fclose(alumno);
							fclose(ctdcursos);
							getch();
							return;
						}
						fread(&Eva1, sizeof(Eva1), 1,prueba1);
					}
				
				strcpy(Eva1.carnetalum, auxnom);
				
				cout<<"\n - Nombre del Catedratico: ";
				cin>>auxcar;
				
				fread(&Ctd, sizeof(Ctd), 1,ctdcursos);
					while(!feof(ctdcursos)){
						if(strcmp(Ctd.nombre_cat, auxcar)==0){
							encontra=true;
				    		cout<<"\n - Curso: "<<Ctd.nombre_curso_seccion<<endl;
				    		cout<<"\n - Seccion: "<<Ctd.seccioncat<<endl;
						}
						fread(&Ctd, sizeof(Ctd), 1,ctdcursos);
					}
					
				strcpy(Eva1.catedratico1, auxcar);	
					
				if(encontra==false){
					cout<<"\n\n NO EXSITE EL CATEDRATICO CON ESE NOMBRE";
						fclose(prueba1);
						fclose(carrera);
						fclose(alumno);
						fclose(ctdcursos);
					getch();
					return;
				}	
				cout<<"\n-------------------------------------------------------------------------------";
				cout<<"\n\n - Estimados Alumnos:";
				cout<<"\n - Con base en su criterio formal y objetivo, le solicitamos su opinion acerca del desempeno de sus docentes,";
				cout<<"\n -utilizando la escala de Indicadores EX = excelente, MB = muy bueno, B= Bueno, NM= Necesita mejorar.";
				cout<<"\n - Tomando en cuenta lo anterior POR FAVOR ESCRIBIR LOS INDICADORES EN LAS SIGIENTES PREGUNTAS EN MAYUSCULA: ";
				cout<<"\n-------------------------------------------------------------------------------"<<endl;
				cout<<"\n\n - Asistencia y Puntualidad a su clase: ";
				cin>>Eva1.evaluacion1;
				cout<<"\n - Conocimiento y Dominio de los temas: ";
				cin>>Eva1.evaluacion2;
				cout<<"\n - Presentacion dosificacion curso al inicio del semestre: ";
				cin>>Eva1.evaluacion3;
				cout<<"\n - Utiliza las herramientas tecnologicas provistas en el aula: ";
				cin>>Eva1.evaluacion4;
				cout<<"\n - Utilizacion de la Plataforma virtual para gestionar su curso: ";
				cin>>Eva1.evaluacion5;
				cout<<"\n - Evaluacion de actividades academicas en orden y con equidad: ";
				cin>>Eva1.evaluacion6;
				cout<<"\n-------------------------------------------------------------------------------";
				fwrite(&Eva1, sizeof(Eva1), 1,prueba1);
				fclose(prueba1);
				fclose(carrera);
				fclose(alumno);
				fclose(ctdcursos);
				sleep(2);
				getch();
				return;
}