#include <stdio.h>
#include <string.h>

/*
    Realizar una función que reciba como argumentos, una letra y una cadena de
    caracteres y devuelva la cantidad de veces en que aparece esa letra en la cadena.
*/

int contadorLetras(char letra, const char* cadena){
    int contador;

   for (int i = 0; cadena[i] != '\0'; i++){
    if(cadena[i] == letra){
        contador++;
    }
   }

   return contador;
}

int main(){
    char letra, cadena[100];

    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';

    printf("Ingrese el caracter que quiere buscar dentro de la cadena anterior: ");
    scanf("%c", &letra);

    int cantidadLetra = contadorLetras(letra, cadena);

    printf("La letra %c se repite %d veces", letra, cantidadLetra);

    return 0;
}