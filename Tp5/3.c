#include <stdio.h>

/*
    Crear una función que devuelva el valor de 𝑅𝑒𝑞𝑢𝑖𝑣 de esta expresión pasándole los
valores de 𝑅1, 𝑅2 y 𝑅3.

*/

double valorRequiv(float R1, float R2, float R3)
{
    float denominador = (1 / R1) + (1 / R2) + (1 / R3);
    float rEquivalente = 1 / denominador;

    printf("\nEl valor de la resistencia equivalente es de: %.2f", rEquivalente);

    return 0;
}

int main()
{
    float R1, R2, R3;

    printf("Ingrese el valor de R1: ");
    scanf("%f", &R1);
    printf("\nIngrese el valor de R2: ");
    scanf("%f", &R2);
    printf("\nIngrese el valor de R3: ");
    scanf("%f", &R3);

    valorRequiv(R1, R2, R3);

    return 0;
}