#include <stdio.h>

/*
    Realizar una función que devuelva el factorial de un número entero, ingresando el
número como argumento.
*/

int factorial(int numero){
    int calculo = numero;
    for(int i = 1; i < numero; i++){
        calculo = calculo * i;
    }

    return calculo;
}

int main(){
    int numero, numeroFactorial;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    numeroFactorial = factorial(numero);

    printf("\nEl factorial del numero %d es %d", numero, numeroFactorial);

    return 0;
}