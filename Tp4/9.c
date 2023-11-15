#include <stdio.h>
#include <math.h>
#define pi 3.14

/*
	Ampliar el programa anterior generando un tercer arreglo P, donde cada elemento
P(i) sea el promedio de los valores de la funcion para los indices i, i+1 e i+2. Es decir:
P(i)=[S(i)+S(i+1)+S(i+2)]/3. Mostrar en forma de tabla.
*/

int main()
{

	double S[36];
	double A[36];
	double P[36];
	double x, rad;

	for (int i = 0; i < 36; i++)
	{
		x = i * 10;
		rad = x * (pi / 180);
		S[i] = sin(rad);
		A[i] = x;
	}

	for (int i = 0; i < 36; i++)
	{
		P[i] = (S[i] + S[i + 1] + S[i + 2]) / 3;
	}

	printf("Angulo     |     Funcion seno     |     Promedio\n\n");
	for (int i = 0; i < 36; i++)
	{
		printf("%0.2f     |     %0.3f     |     %0.2f\n", A[i], S[i], P[i]);
	}

	return 0;
}
