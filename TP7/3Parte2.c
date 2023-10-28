#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file_in, *file_out;
    file_in = fopen("valoresSen4X.txt", "r");
    file_out = fopen("derivadaSen4X.txt", "w");
    if (file_in == NULL || file_out == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    double x[81], y[81], dy[81];
    int i = 0;

    while (fscanf(file_in, "x: %lf, y: %lf\n", &x[i], &y[i]) == 2)
    {
        i++;
    }

    int n = i;
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dy[i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
        }
        else if (i == n - 1)
        {
            dy[i] = (y[i] - y[i - 1]) / (x[i] - x[i - 1]);
        }
        else
        {
            dy[i] = (y[i + 1] - y[i - 1]) / (x[i + 1] - x[i - 1]);
        }
        fprintf(file_out, "x: %.2f, dy: %.2f\n", x[i], dy[i]);
    }

    fclose(file_in);
    fclose(file_out);
    printf("Las derivadas se guardaron en el archivo 'derivadaSen4X.txt'\n");

    return 0;
}
