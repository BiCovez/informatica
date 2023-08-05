#include <stdio.h>

/*
	Realizar un programa donde se rellene un arreglo con los 20 primeros numeros
primos. Mostrar en pantalla los elementos del arreglo.

*/

int main() {
    int numerosPrimos[20], contador = 0, numero = 2; 

    while (contador < 20) {
        int esPrimo = 1; 

        for (int i = 2; i <= numero / 2; i++) {
            if (numero % i == 0) {
                esPrimo = 0; 
                break;
            }
        }

        if (esPrimo) {
            numerosPrimos[contador] = numero;
            contador++;
        }
        numero++;
    }

    printf("Los primeros 20 numeros primos son: \n\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", numerosPrimos[i]);
    }

    return 0;
}
