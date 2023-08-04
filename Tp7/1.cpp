#include <stdio.h>
#include <math.h>

#define pi 3.14159265358979323846
#define valores 81
#define FILENAME "sen2xValores.txt"

/*

Realizar un programa que guarde en un archivo 81 valores de la función y= sen 2 x para x
que varía entre 0 y 8π. Importarlo con EXCEL y graficar

*/

double funcionPotencia(double x) {
    return pow(sin(x), 2);
}

int main() {
    FILE *fp;
    float x, y;
    double step = 8 * pi / (valores - 1); 

    fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("No se inicializo el archivo txt\n");
        return 1;
    }

    for (int i = 0; i < valores; i++) {
        x = i * step;
        y = funcionPotencia(x);
        fprintf(fp, "%lf %lf\n", x, y);
    }

    fclose(fp);
    printf("Datos guardados en el archivo '%s'\n", FILENAME);
    return 0;
}
