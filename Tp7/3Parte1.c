#include <stdio.h>
#include <math.h>

#define pi 3.14
#define valores 81
#define FILENAME "sen4xValores.txt"

/*
Realizar un programa que guarde en un archivo 81 valores de la función y= sen(4x )para x
que varía entre 0 y 8π. Luego realizar un programa que lea los valores del archivo generado y
calcule mediante un método de aproximación, la derivada en cada punto y los guarde los
valores en otro archivo. Importarlo con EXCEL y graficar los 2 archivos.
*/

int main() {
    FILE *fp;
    float x, y;
    double h = 8 * pi / (valores - 1);

    fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("No se pudo inicializar el archivo\n");
        return 1;
    }

    for (int i = 0; i < valores; i++) {
        x = i * h;
        y = sin(4 * x);
        fprintf(fp, "%f %f\n", x, y);
    }

    fclose(fp);
    printf("Los datos y el archivo '%s' se generaron correctamente\n", FILENAME);
    return 0;
}
