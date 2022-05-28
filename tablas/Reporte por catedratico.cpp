#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"Estructuras.hpp"

using namespace std;

void reporteXCatedratico(void){
	
	bool rep=false;
	
	FILE *prueba1;
	FILE *prueba2;
	FILE *prueba3;
	
	int x=0,z=0,c=0,a=0;
	int s=0,d=0,f=0,g=0;
	int q=0,w=0,e=0,r=0;
	int res1,res2,res3;
	
	char auxnom[50];
	struct tipo_evaluacion1 Eva1;
	struct tipo_evaluacion2 Eva2;
	struct tipo_evaluacion3 Eva3;
	
	prueba1 =fopen("Prueba1.txt","r+");
	prueba2 =fopen("Prueba2.txt","r+");
	prueba3 =fopen("Prueba3.txt","r+");
	
	if(prueba1==NULL && prueba2==NULL && prueba3==NULL){
		cout<<"\n NO EXISTE NINGUNA EVALUACION";
		fclose(prueba1);
		fclose(prueba2);
		fclose(prueba3);
		getch();
		return;
	}
	
		cout<<"\n\r REPORTE POR CATEDRATICO EVALUADO";
		cout<<"\n-------------------------------------------------------------------------------";
		cout<<"\n\n Ingrese el Nombre del Catedratico que desea ver el Reporte: ";
		cin>>auxnom;
		
		fread(&Eva1, sizeof(Eva1), 1,prueba1);
			while(!feof(prueba1)){
				if(strcmp(Eva1.catedratico1, auxnom)==0){
					rep=true;
					if(strcmp(Eva1.evaluacion1, "EX")==0){
						x++;
					}
					
					if(strcmp(Eva1.evaluacion1, "MB")==0){
						z++;
					}
					
					if(strcmp(Eva1.evaluacion1, "B")==0){
						c++;
					}
					
					if(strcmp(Eva1.evaluacion1, "NM")==0){
						a++;
					}
				}
			fread(&Eva1, sizeof(Eva1), 1,prueba1);
			}
	if(rep==false){
		cout<<"\n NO EVALUACIONES CON EL CATEDRATICO";
		fclose(prueba1);
		fclose(prueba2);
		fclose(prueba3);
		getch();
		return;
	}
	
		fread(&Eva2, sizeof(Eva2), 1,prueba2);
			while(!feof(prueba2)){
				if(strcmp(Eva2.catedratico2, auxnom)==0){
					rep=true;
					if(strcmp(Eva2.evaluacion2, "EX")==0){
						q++;
					}
					
					if(strcmp(Eva2.evaluacion2, "MB")==0){
						w++;
					}
					
					if(strcmp(Eva2.evaluacion2, "B")==0){
						e++;
					}
					
					if(strcmp(Eva2.evaluacion2, "NM")==0){
						r++;
					}
				}
			fread(&Eva2, sizeof(Eva2), 1,prueba2);
			}
		
		fread(&Eva3, sizeof(Eva3), 1,prueba3);
			while(!feof(prueba3)){
				if(strcmp(Eva3.catedratico3, auxnom)==0){
					rep=true;
					if(strcmp(Eva3.evaluacion3, "EX")==0){
						s++;
					}
					
					if(strcmp(Eva3.evaluacion3, "MB")==0){
						d++;
					}
					
					if(strcmp(Eva3.evaluacion3, "B")==0){
						f++;
					}
					
					if(strcmp(Eva3.evaluacion3, "NM")==0){
						g++;
					}
				}
			fread(&Eva3, sizeof(Eva3), 1,prueba3);
			}
		
		res3=s+d+f+g;	
		res2=q+w+e+r;	
		res1=x+z+c+a;
		
		system("cls");
		cout<<"\n Catedratico: "<<auxnom;
		cout<<"\n-----------------------------------";
		cout<<"\n\t\t\t\t\t\t\t    Total EX \t Total MB \t Total B \t Total NM \t Total";
		cout<<"\n Asistencia y Puntualidad a su clase:\t\t\t\t"<<x<<"\t    "<<z<<"\t\t   "<<c<<"\t\t   "<<a<<"\t\t   "<<res1;
		cout<<"\n Conocimiento y Dominio de los temas:\t\t\t\t"<<q<<"\t    "<<w<<"\t\t   "<<e<<"\t\t   "<<r<<"\t\t   "<<res2;
		cout<<"\n Presentacion dosificacion curso al inicio del semestre:\t"<<x<<"\t    "<<z<<"\t\t   "<<c<<"\t\t   "<<a<<"\t\t   "<<res1;
		
		
		fclose(prueba1);
		fclose(prueba2);
		fclose(prueba3);
		getch();
		return;
}