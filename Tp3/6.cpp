#include <stdio.h>
#include <math.h>

/*
	Realizar un programa en C, que calcule el �rea bajo la curva (integral definida)
de la funci�n y=sen2(x), usando el m�todo de los rect�ngulos sucesivos, entre
dos puntos x1 y x2 que se ingresan por teclado.

*/

float potencia(float x) {
    return pow(sin(x), 2);
}

double areaBajoCurva(double x1, double x2, int numRectangulos) {
    double deltaX = (x2 - x1) / numRectangulos;
    double area = 0.0;

    for (int i = 0; i < numRectangulos; i++) {
        double xMid = x1 + (i + 0.5) * deltaX; 
        double altura = potencia(xMid); 
        area += altura * deltaX; 
    }

    return area;
}

int main() {
    double x1, x2;
    int numRectangulos;

    printf("Ingrese el valor de x1: ");
    scanf("%lf", &x1);

    printf("Ingrese el valor de x2: ");
    scanf("%lf", &x2);

    printf("Ingrese el número de rectángulos a utilizar: ");
    scanf("%d", &numRectangulos);

    double resultado = areaBajoCurva(x1, x2, numRectangulos);

    printf("El área bajo la curva y=sin^2(x) entre %lf y %lf es: %lf\n", x1, x2, resultado);

    return 0;
}
