#include <stdio.h>
#include <math.h>

int main()
{
    FILE *file;
    file = fopen("valoresMuestra.txt", "r");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    double valor, suma = 0, sumaCuadrados = 0;
    int i = 0;

    while (fscanf(file, "%lf", &valor) == 1)
    {
        suma += valor;
        sumaCuadrados += pow(valor, 2);
        i++;
    }

    fclose(file);

    if (i > 0)
    {
        double promedio = suma / i;
        double errorCuadraticoMedio = sqrt(sumaCuadrados / i - pow(promedio, 2));
        printf("Promedio: %.2f \nError cuadratico medio: %.2f\n", promedio, errorCuadraticoMedio);
    }
    else
    {
        printf("El archivo esta vacío\n");
    }

    return 0;
}
