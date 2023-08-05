#include <stdio.h>
#include <math.h>
#define pi 3.14

/*
	Realizar un programa donde se rellene dos arreglos de 36 elementos, uno que
llamaremos S(i)con los valores de la funcion y=seno(x) para x que var�a en 10 grados
sexagesimales , y el otro arreglo A(i) conteniendo los valores de x. Mostrar los dos
arreglos en forma de tabla con una columna para el angulo y otra para la funci�n.

*/

int main(){
	
	double S[36];
	double A[36];
	double x, rad;

	for(int i = 0; i < 36; i++){
		x = i * 10;
		rad = x * (pi / 180);
		S[i] = sin(rad);
		A[i] = x;
	}
	
	printf("Angulo     |     Funcion seno\n\n");
	for(int i = 0; i < 36; i++){
		printf("%0.2f     |     %0.3f\n", A[i], S[i]);
	}
	
	return 0;
	
}
