#include <stdio.h>
#include <math.h>

/*
    Crear una función que devuelva las raíces de la ecuación cuadrática
*/

double formulaResolvente(double a, double b, double c)
{
    double x1, x2;
    double discriminante = b * b - 4 * a * c;

    if (discriminante > 0)
    {
        x1 = (-b + sqrt(discriminante)) / (2 * a);
        x2 = (-b - sqrt(discriminante)) / (2 * a);
    }
    else if (discriminante == 0)
    {
        x1 = -b / (2 * a);
        printf("La ecuacion tiene una unica raiz:\n");
        printf("El valor de x = %.2f\n", x1);
    }
    else
    {
        double parteReal = -b / (2 * a);
        double parteImaginaria = sqrt(-discriminante) / (2 * a);
        printf("La ecuacion tiene raices imaginarias:\n");
        printf("El valor de x1 = %.2f + %.2fi\n", parteReal, parteImaginaria);
        printf("El valor de x2 = %.2f - %.2fi\n", parteReal, parteImaginaria);
    }

    return 0;
}

int main()
{
    double a, b, c;

    printf("Ingrese el valor del coeficiente a: ");
    scanf("%lf", &a);
    printf("Ingrese el valor del coeficiente b: ");
    scanf("%lf", &b);
    printf("Ingrese el valor del coeficiente c: ");
    scanf("%lf", &c);

    formulaResolvente(a, b, c);

    return 0;
}