#include <stdio.h>
#include <math.h>

/*
    Crear una función que devuelva la distancia entre 2 puntos en el espacio, ingresando
las coordenadas x, y, z de cada punto como argumentos de la función.
*/

float vector3D(float x1, float x2, float y1, float y2, float z1, float z2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
}

int main(){
    float x1, x2, y1, y2, z1, z2, distancia;

    printf("Ingrese el valor de X1: ");
    scanf("%f", &x1);
    printf("\nIngrese el valor de X2: ");
    scanf("%f", &x2);
    printf("\nIngrese el valor de Y1: ");
    scanf("%f", &y1);
    printf("\nIngrese el valor de Y2: ");
    scanf("%f", &y2);
    printf("\nIngrese el valor de Z1: ");
    scanf("%f", &z1);
    printf("\nIngrese el valor de Z2: ");
    scanf("%f", &z2);

    distancia = vector3D(x1, x2, y1, y2, z1, z2);

    printf("El vector resultante de los tres puntos es %.2f", distancia);

    return 0;
}