#include <stdio.h>
#include <math.h>

#define pi 3.14159265358979323846
#define valores 81
#define FILENAME_IN "sen4xValores.txt"
#define FILENAME_OUT "derivadaValores.txt"

/*
Realizar un programa que guarde en un archivo 81 valores de la función y= sen(4x )para x
que varía entre 0 y 8π. Luego realizar un programa que lea los valores del archivo generado y
calcule mediante un método de aproximación, la derivada en cada punto y los guarde los
valores en otro archivo. Importarlo con EXCEL y graficar los 2 archivos. 
*/

double derivadaPorAproximacion(float y1, float y2, float h) {
    return (y2 - y1) / h;
}

int main() {
    FILE *fp_in, *fp_out;
    double x, y, y_next;
    double step = 8 * pi / (valores - 1);

    fp_in = fopen(FILENAME_IN, "r");
    if (fp_in == NULL) {
        printf("No se pudo inicializar el archivo de entrada\n");
        return 1;
    }

    fp_out = fopen(FILENAME_OUT, "w");
    if (fp_out == NULL) {
        printf("No se pudo inicializar el archivo de salida\n");
        fclose(fp_in);
        return 1;
    }

    fscanf(fp_in, "%lf %lf", &x, &y);
    fprintf(fp_out, "%f %f\n", x, 0.0); 
    for (int i = 1; i < valores; i++) {
        fscanf(fp_in, "%lf %lf", &x, &y_next);
        float derivada = derivadaPorAproximacion(y, y_next, step);
        fprintf(fp_out, "%f %f\n", x, derivada);
        y = y_next;
    }

    fclose(fp_in);
    fclose(fp_out);
    printf("El archivo con resultado de derivadas fue creado correctamente.\n", FILENAME_OUT);
    return 0;
}
