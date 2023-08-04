#include <stdio.h>
#include <math.h>

/*
     Realizar un programa donde se utilice una función que calcule las raíces de la
    ecuación cuadrática A x 2 +B x +C =0. Utilizar paso de argumentos por referencia
*/


void cuadratica(float a, float b, float c, float* x1, float* x2) {
    float d;
    
    d = b * b - 4 * a * c;

    if (d >= 0) {
        *x1 = (-b + sqrt(d)) / (2 * a);
        *x2 = (-b - sqrt(d)) / (2 * a);
        printf("x1 = %.2f\n", *x1);
        printf("x2 = %.2f\n", *x2);
    } else {
        printf("Error: raices complejas\n");
    }
}

int main() {
    float a, b, c;
    float x1, x2;

    printf("Ingrese el valor del coeficiente a: ");
    scanf("%f", &a);

    printf("Ingrese el valor del coeficiente b: ");
    scanf("%f", &b);

    printf("Ingrese el valor del termino independiente c: ");
    scanf("%f", &c);

    cuadratica(a, b, c, &x1, &x2);

    return 0;
}
