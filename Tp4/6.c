#include <stdio.h>

/*
    Realizar un programa en C que lea 10 numeros enteros, los cargue en un arreglo y
luego los ordene en el arreglo de manera descendente.
*/

void bubblesort(int arreglo[], int tamaño)
{
    int i, j;
    for (i = 0; i < tamaño - 1; i++)
    {
        for (j = 0; j < tamaño - i - 1; j++)
        {
            if (arreglo[j] < arreglo[j + 1])
            {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arreglo[10];
    printf("Ingrese 10 numeros\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arreglo[i]);
    }

    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);

    bubblesort(arreglo, tamaño);

    printf("Array ordenado de mayor a menor:\n");
    for (int i = 0; i < tamaño; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}
