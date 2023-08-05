#include <stdio.h>
#include <math.h>

/*
	Realizar un programa que obtenga la derivada de la funcion en un punto de la
funcion y=sen2(x). Ingresando por teclado el valor del punto donde se hara el
calculo. Mostrar el valor de la derivada.
*/

int main(){
	float x, derivada;
	printf("Ingrese el valor del punto x para calcular la derivada: ");
	scanf("%f", &x);
	
	derivada = 2 * sin(x) * cos(x);
	
	printf("\nLa derivada del punto %.2f es %.2f", x, derivada);
	
	return 0;
}
