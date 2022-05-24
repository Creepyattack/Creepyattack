#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <stdlib.h>

struct tipo_alumno{
	
	char nombre_alumno[50];
	char carnet[50];
	char alumno_carrera[50];
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

struct secciones{
	
	char seccion[50];
};