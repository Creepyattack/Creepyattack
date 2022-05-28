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
	FILE *prueba4;
	FILE *prueba5;
	FILE *prueba6;
	
	int t=0,y=0,u=0,i=0;
	int h=0,j=0,k=0,l=0;
	int v=0,b=0,n=0,m=0;
	int x=0,z=0,c=0,a=0;
	int s=0,d=0,f=0,g=0;
	int q=0,w=0,e=0,r=0;
	int res1,res2,res3,res4,res5,res6;
	
	char auxnom[50];
	struct tipo_evaluacion1 Eva1;
	struct tipo_evaluacion2 Eva2;
	struct tipo_evaluacion3 Eva3;
	struct tipo_evaluacion4 Eva4;
	struct tipo_evaluacion5 Eva5;
	struct tipo_evaluacion6 Eva6;
	
	prueba1 =fopen("Prueba1.txt","r+");
	prueba2 =fopen("Prueba2.txt","r+");
	prueba3 =fopen("Prueba3.txt","r+");
	prueba4 =fopen("Prueba4.txt","r+");
	prueba5 =fopen("Prueba5.txt","r+");
	prueba6 =fopen("Prueba6.txt","r+");
	
	if(prueba1==NULL){
		cout<<"\n NO EXISTE NINGUNA EVALUACION";
		fclose(prueba1);
		fclose(prueba2);
		fclose(prueba3);
		fclose(prueba4);
		fclose(prueba5);
		fclose(prueba6);
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
		fclose(prueba4);
		fclose(prueba5);
		fclose(prueba6);
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
			
		fread(&Eva4, sizeof(Eva4), 1,prueba4);
			while(!feof(prueba4)){
				if(strcmp(Eva4.catedratico4, auxnom)==0){
					rep=true;
					if(strcmp(Eva4.evaluacion4, "EX")==0){
						t++;
					}
					
					if(strcmp(Eva4.evaluacion4, "MB")==0){
						y++;
					}
					
					if(strcmp(Eva4.evaluacion4, "B")==0){
						u++;
					}
					
					if(strcmp(Eva4.evaluacion4, "NM")==0){
						i++;
					}
				}
			fread(&Eva4, sizeof(Eva4), 1,prueba4);
			}
		
		fread(&Eva5, sizeof(Eva5), 1,prueba5);
			while(!feof(prueba5)){
				if(strcmp(Eva5.catedratico5, auxnom)==0){
					rep=true;
					if(strcmp(Eva5.evaluacion5, "EX")==0){
						h++;
					}
					
					if(strcmp(Eva5.evaluacion5, "MB")==0){
						j++;
					}
					
					if(strcmp(Eva5.evaluacion5, "B")==0){
						k++;
					}
					
					if(strcmp(Eva5.evaluacion5, "NM")==0){
						l++;
					}
				}
			fread(&Eva5, sizeof(Eva5), 1,prueba5);
			}
		
		fread(&Eva6, sizeof(Eva6), 1,prueba6);
			while(!feof(prueba6)){
				if(strcmp(Eva6.catedratico6, auxnom)==0){
					rep=true;
					if(strcmp(Eva6.evaluacion6, "EX")==0){
						v++;
					}
					
					if(strcmp(Eva6.evaluacion6, "MB")==0){
						b++;
					}
					
					if(strcmp(Eva6.evaluacion6, "B")==0){
						n++;
					}
					
					if(strcmp(Eva6.evaluacion6, "NM")==0){
						m++;
					}
				}
			fread(&Eva6, sizeof(Eva6), 1,prueba6);
			}
		
		res4=t+y+u+i;
		res5=h+j+k+l;
		res6=v+b+n+m;
		res3=s+d+f+g;	
		res2=q+w+e+r;	
		res1=x+z+c+a;
		
		system("cls");
		cout<<"\n Catedratico: "<<auxnom;
		cout<<"\n------------------------------------------------------------------------------------------------------------------------------------";
		cout<<"\n\t\t\t\t\t\t\t    Total EX \t Total MB \t Total B \t Total NM \t Total";
		cout<<"\n Asistencia y Puntualidad a su clase:\t\t\t\t"<<x<<"\t    "<<z<<"\t\t   "<<c<<"\t\t   "<<a<<"\t\t   "<<res1;
		cout<<"\n Conocimiento y Dominio de los temas:\t\t\t\t"<<q<<"\t    "<<w<<"\t\t   "<<e<<"\t\t   "<<r<<"\t\t   "<<res2;
		cout<<"\n Presentacion dosificacion curso al inicio del semestre:\t"<<s<<"\t    "<<d<<"\t\t   "<<f<<"\t\t   "<<g<<"\t\t   "<<res3;
		cout<<"\n Utiliza las herramientas tecnologicas provistas en el aula:\t"<<t<<"\t    "<<y<<"\t\t   "<<u<<"\t\t   "<<i<<"\t\t   "<<res4;
		cout<<"\n Utilizacion de la Plataforma virtual para gestionar su curso:\t"<<h<<"\t    "<<j<<"\t\t   "<<k<<"\t\t   "<<l<<"\t\t   "<<res5;
		cout<<"\n Evaluacion de actividades academicas en orden y con equidad:\t"<<v<<"\t    "<<b<<"\t\t   "<<n<<"\t\t   "<<m<<"\t\t   "<<res6;
		cout<<"\n------------------------------------------------------------------------------------------------------------------------------------";
		
		
		fclose(prueba1);
		fclose(prueba2);
		fclose(prueba3);
		getch();
		return;
}