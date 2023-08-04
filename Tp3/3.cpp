#include <stdio.h>
#include <math.h>
#define pi 3.14

/*
	Realizar un programa en C, que muestre 50 valores de la función:
y=sen(x)+0.7cos(2x)+0.5sen(3x) entre x=0 y x=4pi
Copiar los valores en una planilla de Excel y graficar.

*/

int main(){
	float x, y;
	
	for (int i = 0; i < 50; i++){
		x = i * 4 * pi / 49;
		y = sin(x) + 0.7 * cos(2 * x) + 0.5 * sin(3 * x);
		printf("X = %.2f\t Y = %.2f\n", x, y);
	}
	
	return 0;
}
