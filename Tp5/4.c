#include <stdio.h>

/*
    Crear una función que devuelva el número menor de 3 números enteros ingresados
como argumentos de la función.
*/

int numeroMenor(int valor1, int valor2, int valor3){
    int min;
    if(valor1 < valor2){
        if(valor1 < valor3){
            min = valor1;
        }
        else{
            min = valor3;
        }
    }
    else{
    if(valor2 < valor3){
        min = valor2;
        }
        else{
            min = valor3;
        }
    }
    return min;
}

int main(){
    int valor1, valor2, valor3;
    printf("Ingrese 3 valores\n");
    scanf("%d %d %d", &valor1, &valor2, &valor3);
    printf("El numero menor es: %d\n", numeroMenor(valor1, valor2, valor3));
    return 0;
}