#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main()
{
    FILE *file;
    file = fopen("valoresSen4X.txt", "w");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    double x, y;
    for (int i = 0; i <= 80; i++)
    {
        x = i * 8 * PI / 80;
        y = sin(4 * x);
        fprintf(file, "x: %.2f, y: %.2f\n", x, y);
    }

    fclose(file);
    printf("Los valores se guardaron en el archivo 'valoresSen4X.txt'\n");

    return 0;
}
