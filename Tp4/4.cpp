#include <stdio.h>

/*
	Hacer un programa en C que permita cargar las notas (entre 0 y 10 puntos) de 15
alumnos y luego se determine la frecuencia de cada nota, es decir la cantidad de
alumnos que obtuvieron cada nota en particular.
*/

int main(){
	int notasAlumnos[15], notas[11] = {0,1,2,3,4,5,6,7,8,9,10}, notasRepetidas[11] = {0,0,0,0,0,0,0,0,0,0,0}, j = 0;
	
	for(int i = 0; i < 15; i++){
		printf("Ingrese la nota del alumno %d: ", i+1);
		scanf("%d", &notasAlumnos[i]);
		
		if(notasAlumnos[i] < 0 || notasAlumnos[i] > 10){
			printf("\n\nNota invalida, ingrese nuevamente la nota: ");
			i--;
			scanf("%d", &notasAlumnos[i]);
		}
		
		while(notasAlumnos[i] != notas[j]){
			j++;
		}
		if(notasAlumnos[i] == notas[j]){
			notasRepetidas[j]++;
			j = 0;
		}
	}
	for(int i = 0; i < 11; i++){
		printf("La nota %d se repitio %d veces\n", notas[i], notasRepetidas[i]);
	}
	
	return 0;
	
}
