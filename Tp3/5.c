#include <stdio.h>
#include <math.h>
#define pi 3.14

/*
	Realizar un programa en C, que muestre 50 valores de la funcion:
y=sen(x) entre x=0 y x=4pi y de la derivada de la misma
Copiar los valores en una planilla de Excel, graficar y comparar.

*/

int main(){
	float x, y, derivada;
	
	for (int i = 0; i < 50; i++){
		x = i * 4 * pi / 49;
		y = sin(x);
		derivada = cos(x);
		printf("X = %.2f\t Y = %.2f\n", x, y);
		printf("La derivada del punto %.2f es %.2f\n\n", x, derivada);
	}
	
	return 0;
}
