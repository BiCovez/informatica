#include <stdio.h>
#include <string.h>

/*
    Realizar una función que reciba como argumento dos cadenas de caracteres y
    obtenga otra que sea la unión de la primera con la segunda cadena
*/

void unirCadenas(const char* cadena1, const char* cadena2, char* resultado) {
    strcpy(resultado, cadena1); 
    strcat(resultado, cadena2); 
}

int main() {
    char cadena1[100];
    char cadena2[100];
    char resultado[200];

    printf("Ingrese la primera cadena: ");
    fgets(cadena1, sizeof(cadena1), stdin);
    cadena1[strcspn(cadena1, "\n")] = '\0'; 

    printf("Ingrese la segunda cadena: ");
    fgets(cadena2, sizeof(cadena2), stdin);
    cadena2[strcspn(cadena2, "\n")] = '\0';

    unirCadenas(cadena1, cadena2, resultado);

    printf("La cadena resultante es: %s\n", resultado);

    return 0;
}
