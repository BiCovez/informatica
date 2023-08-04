#include <stdio.h>
#define pi 3.14

/*
    Crear una función que dado el radio devuelva la longitud de la circunferencia o el
área del círculo o el volumen de la esfera, través de un segundo parámetro que
seleccione cualquiera de estas tres opciones
*/

double calculadora(float radio, int opcion){
    float longitud, area, volumen;

    if(opcion == 1){
        longitud = 2 * pi * radio;
        return longitud;
    }
    else if(opcion == 2){
        area = pi * (radio * radio);
        return area;
    }
    else if(opcion == 3){
        volumen = 4 / 3 * pi * (radio * radio * radio);
        return volumen;
    }
}

int main(){
    float radio;
    int opcion;

    printf("Ingrese el radio: ");
    scanf("%f", &radio);

    printf("Hay 3 opciones para realizar el calculo\n- 1) Calcular la longitud de la circunferencia\n- 2) Calcular el area del circulo\n- 3) Calcular el volumen de la esfera\n");

    printf("Ingrese la opcion a calcular: ");
    scanf("%d", &opcion);

    float calculo = calculadora(radio, opcion);

    printf("El calculo elegido fue %d y el resultado es %.2f", opcion, calculo);

    return 0;
}