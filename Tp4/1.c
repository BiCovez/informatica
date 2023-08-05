#include <stdio.h>
#include <math.h>

/*
	Hacer un programa en C que lea 5 valores de muestras de un ensayo, calcule el
promedio y el valor cuadratico medio del error respecto al promedio
*/

int main(){
	int valoresMuestra[5];
	float promedio, valoresCuadraticos, errorCuadratico;
	
	printf("Ingrese los valores de la muestra\n");
	for(int i = 0; i < 5; i++){
		scanf("%d", &valoresMuestra[i]);
		promedio += valoresMuestra[i];
		valoresCuadraticos += valoresMuestra[i] * valoresMuestra[i];
	}
	promedio = promedio / 5;
	printf("El promedio de los 5 valores ingresados es de %.2f\n", promedio);
	
	errorCuadratico = sqrt(valoresCuadraticos / 5);
	printf("El error cuadratico de los valores medidos es de %.2f\n", errorCuadratico);
}
