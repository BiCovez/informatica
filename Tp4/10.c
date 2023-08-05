#include <stdio.h>
#include <string.h>

/*
	Realizar un programa en C que lea una cadena y la muestre al revés.
*/

int main(){
	char cadena[100];
	printf("Ingrese una cadena: ");
	fgets(cadena, sizeof(cadena), stdin);
	
	int longitud = strlen(cadena);
	if(cadena[longitud - 1] == '\n'){
		cadena[longitud - 1] = '\0';
		longitud--;
	}
	
	printf("\n\nCadena al reves: ");
	for(int i = longitud - 1; i >= 0; i--){
		printf("%c", cadena[i]);
	}
	
	return 0;
}
