#include <stdio.h>

/*  La sucesion de Fibonacci se define de la siguiente forma: a1=1, a2=1 y
an=an-1+an-2 para n>2, es decir los dos primeros son 1 y el resto cada uno es
la suma de los dos anteriores, los primeros son: 1, 1, 2, 3, 5, 8, 13, 21,... hacer
un programa en C para calcular el enesimo termino de la sucesion */

int main() {
    int n, i;
    int a = 1, b = 1, c;

    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    if (n == 1 || n == 2) {
        c = 1;
    } else {
        for (i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
    }

    printf("El enesimo termino de la sucesion de Fibonacci es: %d\n", c);

    return 0;
}
