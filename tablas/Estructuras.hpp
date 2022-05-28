#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <stdlib.h>

struct tipo_alumno{
	
	char nombre_alumno[50];
	char carnet[50];
	char alumno_carrera[50];
	int ciclo_alumno;
};

struct tipo_carrera{
	
	char cod_carrera[10];
	char carrera[50];
};

struct tipo_cursos{
	
	char carrera_curso[50];
	char cod_curso[50];
	char nombre_curso[50];
	int ciclo;
};

struct tipo_seccion{
	
	char seccion[50];
	char nombre_seccion[50];
};

struct tipo_catedraticos{
	
	char codigo_catedratico[50];
	char titulo[50];
	char nombre[50];
};

struct tipo_catedraticos_cursos{
	
	char seccioncat[50];
	char nombre_curso_seccion[50];
	char codigo_CAT[50];
	char nombre_cat[50];
	char titulo_cat[50];
};


struct tipo_evaluacion1{
	
	char carnet1[50];
	char catedratico1[50];
	char evaluacion1[50];
};

struct tipo_evaluacion2{
	
	char carnet2[50];
	char catedratico2[50];
	char evaluacion2[50];
};

struct tipo_evaluacion3{
	
	char carnet3[50];
	char catedratico3[50];
	char evaluacion3[50];
};

struct usuarios{
	
	char usuario[50];
	char contrasena[50];
	char tipo[50];
};