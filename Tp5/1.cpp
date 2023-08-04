#include <stdio.h>

/*
    Crear una función que permita calcular la potencia enésima (exponente entero) de
un número real (float). No utilizar la función de la librería math.
*/

double potenciaEnesima(float numero, int potencia){
    float resultadoPotenciado;

    if(potencia > 0){
        for(int i = 1; i <= potencia; i++){
            resultadoPotenciado = numero * numero;
        }
    }

    return resultadoPotenciado;
}

int main(){
    float numeroReal, resultado;
    int potencia;
    printf("Ingrese el valor del numero real: ");
    scanf("%f", &numeroReal);
    printf("\nIngrese el valor de la potencia: ");
    scanf("%d", &potencia);

    resultado = potenciaEnesima(numeroReal, potencia);

    printf("\nLa potencia %d del numero %.2f es de %.2f", potencia, numeroReal, resultado);

    return 0;
}