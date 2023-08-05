#include <stdio.h>

/*
	Hacer un programa en C donde se lean las notas de 10 alumnos, ingresadas por
teclado y determine la cantidad de alumnos que tuvieron notas por encima del
promedio y la cantidad de alumnos por debajo del promedio.

*/

int main(){
	float alumnos[10], promedioNotas;
	
	for(int i = 0; i < 10; i++){
		printf("Ingrese la nota del alumno %d: ", i+1);
		scanf("%f", &alumnos[i]);
		
		promedioNotas += alumnos[i];
	}
	printf("\n");
	promedioNotas = promedioNotas / 10;
	for (int i = 0; i < 10; i++){
		if(alumnos[i] >= promedioNotas){
			printf("El alumno %d tuvo una nota por encima del promedio\n", i+1);
		}
		else {
			printf("El alumno %d tuvo una nota por debajo del promedio\n", i+1);
		}
	}
}
