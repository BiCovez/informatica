#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main()
{
    FILE *file;
    file = fopen("valoresSenCuadrado.txt", "w");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    double x, y;
    for (int i = 0; i <= 80; i++)
    {
        x = i * 8 * PI / 80;
        y = pow(sin(x), 2);
        fprintf(file, "x: %.2f, y: %.2f\n", x, y);
    }

    fclose(file);
    printf("Los valores se guardaron en el archivo 'valoresSenoCuadrado.txt'\n");

    return 0;
}