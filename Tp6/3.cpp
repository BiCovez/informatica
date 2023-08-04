#include <stdio.h>

/*
     Realizar un programa que utilice una función que intercambie los valores de X1
    y de X2.
*/
void intercambiar(float* x1, float* x2) {
    float temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}

int main() {
    float x1, x2;

    printf("Ingrese el valor de x1: ");
    scanf("%f", &x1);

    printf("Ingrese el valor de x2: ");
    scanf("%f", &x2);

    printf("Antes del intercambio: x1 = %.2f, x2 = %.2f\n", x1, x2);

    intercambiar(&x1, &x2);

    printf("Después del intercambio: x1 = %.2f, x2 = %.2f\n", x1, x2);

    return 0;
}


