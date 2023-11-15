#include <stdio.h>

// Hacer un programa en C para calcular el factorial de N (N!=1*2*3*...*N)

int main()
{
	int numeroIngresado;
	long int factorial;
	printf("Ingrese un numero para calcular su factorial: \n");
	scanf("%d", &numeroIngresado);
	factorial = numeroIngresado;
	for (int i = 1; i < numeroIngresado; i++)
	{
		factorial *= i;
	}
	printf("El factorial del numero %d es: %d", numeroIngresado, factorial);

	return 0;
}
