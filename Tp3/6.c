#include <stdio.h>
#include <math.h>

/*
	Realizar un programa en C, que calcule el area bajo la curva (integral definida)
de la funcion y=sen2(x), usando el metodo de los rectangulos sucesivos, entre
dos puntos x1 y x2 que se ingresan por teclado.

*/

double areaBajoCurva(double x1, double x2, int numRectangulos) {
    double deltaX = (x2 - x1) / numRectangulos;
    double area = 0.0;

    for (int i = 0; i < numRectangulos; i++) {
        double x = x1 + (i + 0.5) * deltaX; 
        double altura = sin(x) * sin(x); 
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
