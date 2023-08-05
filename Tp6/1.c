#include <stdio.h>
#include <math.h>

/*
    Realizar un programa donde se utilice una función de conversión de números
    complejos de forma rectangular a polar y otra función de forma polar a
    rectangular. Utilizar paso de argumentos por referencia.

*/

#include <stdio.h>
#include <math.h>

void conversorRecPolar(float a, float b, float* r, float* angulo) {
    float aCuadrado, bCuadrado;

    aCuadrado = a * a;
    bCuadrado = b * b;

    *r = sqrt(aCuadrado + bCuadrado);
    *angulo = atan2(b, a);

    printf("La conversion de %.2f y %.2f a polar da como resultado:\n", a, b);
    printf("-- %.2f -- %.2f rad --", *r, *angulo);
}

void conversorPolRec(float r, float angulo, float* a, float* b) {
    *a = r * cos(angulo);
    *b = r * sin(angulo);

    printf("La conversion de %.2f y %.2f rad da como resultado:\n", r, angulo);
    printf("-- %.2f -- %.2fi --", *a, *b);
}

int main() {
    int opcion;
    float a, b, r, angulo;

    printf("Ingrese opción a calcular:\n");
    printf("Opción 1: Rectangular a Polar\n");
    printf("Opción 2: Polar a Rectangular\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingrese el valor de a: ");
        scanf("%f", &a);

        printf("Ingrese el valor del número imaginario b: ");
        scanf("%f", &b);

        conversorRecPolar(a, b, &r, &angulo);
    } else if (opcion == 2) {
        printf("Ingrese el valor de r: ");
        scanf("%f", &r);

        printf("Ingrese el valor del ángulo: ");
        scanf("%f", &angulo);

        conversorPolRec(r, angulo, &a, &b);
    }

    return 0;
}
