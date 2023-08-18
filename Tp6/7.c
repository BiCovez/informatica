#include <stdio.h>

/*
    Realizar una función que reciba como argumentos 2 matrices de número reales
    de 3x3 y obtenga el producto de las 2 matrices.
*/
/*nazi*/
void multiplicarMatrices(float matriz1[3][3], float matriz2[3][3]) {
    float resultado[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = 0.0; 
            
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    printf("\nResultado de la multiplicación:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", resultado[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float matriz1[3][3], matriz2[3][3];

    printf("Ingrese los elementos de la primera matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Posicion [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz1[i][j]);
        }
    }

    printf("\nIngrese los elementos de la segunda matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Posicion [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz2[i][j]);
        }
    }

    multiplicarMatrices(matriz1, matriz2);

    return 0;
}
