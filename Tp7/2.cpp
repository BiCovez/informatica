#include <stdio.h>
#include <math.h>

#define valores 20
#define FILENAME "muestra.txt"

/*
 Realizar un programa que lea de un archivo de texto, previamente editado con Block de
Notas, 20 valores de muestra, obtenga el promedio y valor cuadrático medio de error.
*/

int main() {
    FILE *fp;
    double valor, suma = 0.0, promedio, valorCuadratico = 0.0;

    fp = fopen(FILENAME, "r");
    
    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    for (int i = 0; i < valores; i++) {
        if (fscanf(fp, "%lf", &valor) == 1) {
            suma += valores;
        } else {
            printf("Error al leer el valor %d del archivo\n", i + 1);
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    promedio = suma / valores;

    fp = fopen(FILENAME, "r");

    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    for (int i = 0; i < valores; i++) {
        if (fscanf(fp, "%lf", &valor) == 1) {
            valorCuadratico += pow(valor - promedio, 2);
        } else {
            printf("Error al leer el valor %d del archivo.\n", i + 1);
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    valorCuadratico /= valores;
    valorCuadratico = sqrt(valorCuadratico);

    printf("Promedio de los valores de muestra: %f\n", promedio);
    printf("Valor cuadrático medio de error: %f\n", valorCuadratico);

    return 0;
}
