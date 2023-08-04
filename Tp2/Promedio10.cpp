#include <stdio.h>

/* Hacer un programa en C que lea diez n�meros reales por teclado y
obtenga el promedio de los mismos. */

int main(){
	int numerosIngresados[10], suma;
	printf("Ingrese 10 numeros reales para calcular el promedio\n");
	for(int i = 0; i < 10; i++){
		scanf("%d", &numerosIngresados[i]);
		suma += numerosIngresados[i];
	}
	float promedio = suma / 10;
	printf("El promedio de los numeros ingresados es: %.2f", promedio);
	
	return 0;
}
