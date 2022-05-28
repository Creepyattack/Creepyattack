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
	FILE *prueba2;
	FILE *prueba3;
	FILE *ctdcursos;
	FILE *alumno;
	FILE *carrera;
	char auxcod[50],auxnom[50],auxcar[50];
	struct tipo_evaluacion1 Eva1;
	struct tipo_evaluacion2 Eva2;
	struct tipo_evaluacion3 Eva3;
	struct tipo_alumno Alumno;
	struct tipo_catedraticos_cursos Ctd;
	struct tipo_carrera  Carrera;
	
	prueba1 =fopen("Prueba1.txt","r+");
	prueba2 =fopen("Prueba2.txt","r+");
	prueba3 =fopen("Prueba3.txt","r+");
	
	ctdcursos =fopen("Catedraticos_cursos.txt", "r+");
	alumno = fopen("Alumnos.txt", "r+");
	carrera = fopen("Carreras.txt","r+");
	
	if(prueba1==NULL && prueba2==NULL && prueba3==NULL){
		prueba1 =fopen("Prueba1.txt","w+");
		prueba2 =fopen("Prueba2.txt","w+");
		prueba3 =fopen("Prueba3.txt","w+");
		cout<<"\n SE A CREADO EL ARCHIVO DE LAS EVALUACIONES";
		fclose(prueba1);
		fclose(prueba2);
		fclose(prueba3);
		fclose(carrera);
		fclose(alumno);
		fclose(ctdcursos);
		getch();
		return;
	}
	
	cout<<"\t\t EVALUACION DE ESTUDIATES A DOCENTES";
	cout<<"\n-------------------------------------------------------------------------------";
	cout<<"\n\t- Carrera:  ";
	cin>>auxcod;
	
		fread(&Carrera, sizeof(Carrera), 1,carrera);
	        
	        while(!feof(carrera)){
	        	
	        	if(strcmp(Carrera.carrera, auxcod)== 0){
	        		
	        	cout<<"\n\t- Carnet del alumno: ";
				cin>>auxnom;
				
				fread(&Alumno, sizeof(Alumno), 1,alumno);
				    while(!feof(alumno)){
				    	
				    	if(strcmp(Alumno.carnet, auxnom)==0){
				    		encontrado=true;
				    		cout<<"\n\t-Nombre del Estudiante: "<<Alumno.nombre_alumno<<endl;
				    		cout<<"\t-Ciclo: "<<Alumno.ciclo_alumno<<endl;
				    	}
				    	fread(&Alumno, sizeof(Alumno), 1,alumno);
					}
				if(encontrado==false){
					cout<<"\n NO EXSITE EL ALUMNO CON ESE CARNET";
					fclose(prueba1);
					fclose(prueba2);
					fclose(prueba3);
					fclose(carrera);
					fclose(alumno);
					fclose(ctdcursos);
					getch();
					return;
				}
				strcpy(Eva1.carnet1, auxnom);
				strcpy(Eva2.carnet2, auxnom);
				strcpy(Eva3.carnet3, auxnom);
				
				fread(&Eva1, sizeof(Eva1), 1,prueba1);
					while(!feof(prueba1)){
						if(strcmp(Eva1.carnet1, auxnom)==0){
							cout<<"\n ESTE ALUMNO YA HIZO LA EVALUACION";
							fclose(prueba1);
							fclose(prueba2);
							fclose(prueba3);
							fclose(carrera);
							fclose(alumno);
							fclose(ctdcursos);
							getch();
							return;
						}
						fread(&Eva1, sizeof(Eva1), 1,prueba1);
					}
				
				cout<<"\n\t- Nombre del Catedratico: ";
				cin>>auxcar;
				
				fread(&Ctd, sizeof(Ctd), 1,ctdcursos);
					while(!feof(ctdcursos)){
						if(strcmp(Ctd.nombre_cat, auxcar)==0){
							encontra=true;
				    		cout<<"\t- Curso: "<<Ctd.nombre_curso_seccion<<endl;
				    		cout<<"\t- Seccion: "<<Ctd.seccioncat<<endl;
						}
						fread(&Ctd, sizeof(Ctd), 1,ctdcursos);
					}
					
				strcpy(Eva1.catedratico1, auxcar);	
				strcpy(Eva2.catedratico2, auxcar);
				strcpy(Eva3.catedratico3, auxcar);
					
				if(encontra==false){
					cout<<"\n NO EXSITE EL CATEDRATICO CON ESE NOMBRE";
					fclose(prueba1);
					fclose(prueba2);
					fclose(prueba3);
					fclose(carrera);
					fclose(alumno);
					fclose(ctdcursos);
					getch();
					return;
				}	
				
				cout<<"\t\n- Estimados Alumnos:";
				cout<<"\t\n- Con base en su criterio formal y objetivo, le solicitamos su opinion acerca del desempeno de sus docentes,";
				cout<<"\n -utilizando la escala de Indicadores EX = excelente, MB = muy bueno, B= Bueno, NM= Necesita mejorar.";
				cout<<"\t\n- Tomando en cuenta lo anterior POR FAVOR ESCRIBIR LOS INDICADORES EN LAS SIGIENTES PREGUNTAS: ";
				cout<<"\t\n\n- Asistencia y Puntualidad a su clase: ";
				cin>>Eva1.evaluacion1;
				cout<<"\t\n\n- Conocimiento y Dominio de los temas: ";
				cin>>Eva2.evaluacion2;
				cout<<"\t\n- Presentacion dosificacion curso al inicio del semestre: ";
				cin>>Eva3.evaluacion3;
				cout<<"\n-------------------------------------------------------------------------------";
				fwrite(&Eva1, sizeof(Eva1), 1,prueba1);
				fwrite(&Eva2, sizeof(Eva2), 1,prueba2);
				fwrite(&Eva3, sizeof(Eva3), 1,prueba3);
				sleep(5);
				cout<<"\n GRACIAS POR RESPONDER";
				fclose(prueba1);
				fclose(prueba2);
				fclose(prueba3);
				fclose(carrera);
				fclose(alumno);
				fclose(ctdcursos);
				getch();
				return;
	        		
	    	 }
	    	fread(&Carrera, sizeof(Carrera), 1,carrera);
	    }
	    
	    if(w==false){
	    		cout<<"\n ERROR, no existe la carrera con ese nombre"<<endl;
	        		fclose(prueba1);
					fclose(prueba2);
					fclose(prueba3);
					fclose(carrera);
					fclose(alumno);
					fclose(ctdcursos);
	        		getch();
	        		return;
		}
}