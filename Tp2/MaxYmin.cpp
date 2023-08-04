#include <stdio.h>

/* Hacer un programa en C para calcular el máximo y el mínimo de N
números leídos por teclado */

int main(){
	int numeroN, max = 0, min = 0;
	printf("Ingrese que cantidad de numeros desea ingresar: ");
	scanf("%d", &numeroN);
	int numeros[numeroN-1];
	printf("\nIngrese %d numeros para calcular el maximo y minimo\n", numeroN);
	for(int i = 0; i < numeroN; i++){
		scanf("%d", &numeros[i]);
	}
	
	for(int i = 0; i < numeroN; i++){
		if(numeros[i] > max) max = numeros[i];
	}
	min = max;
	for(int i = 0; i < numeroN; i++){
		if(numeros[i] < min) min = numeros[i];
	}
	
	printf("El numeros maximo de los ingresados es: %d\n", max);
	printf("El numero minimo de los ingresados es: %d\n", min);
	 
	return 0;
	
}
