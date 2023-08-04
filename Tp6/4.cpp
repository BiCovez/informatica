#include <stdio.h>
#include <math.h>

/*
    Realizar una función que reciba como argumento una matriz de números reales
    de 3x3 y calcule el determinante
*/

double calculadoraMatriz(int matriz[3][3]){
    float det;

    det = (matriz[0][0] * matriz[1][1] * matriz[2][2]) +
          (matriz[0][1] * matriz[1][2] * matriz[2][0]) +
          (matriz[0][2] * matriz[1][0] * matriz[2][1]) -
          (matriz[2][0] * matriz[1][1] * matriz[0][2]) -
          (matriz[2][1] * matriz[1][2] * matriz[0][0]) -
          (matriz[2][2] * matriz[1][0] * matriz[0][1]);

    return det;
}

int main(){
    int matriz[3][3];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("Ingrese el valor para la posicion [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    float determinante = calculadoraMatriz(matriz);

    printf("El determinante de la matriz ingresada es: %.2f", determinante);

    return 0;
}