#include <stdio.h>
#include <string.h>

/*
	Realizar un programa en C que lea una cadena y la encripte sumando 3 al c�digo
ASCII de cada car�cter. Mostrar por pantalla.
*/

int main(){
	char cadena[100];
	
	printf("Ingrese una cadena de texto: ");
	fgets(cadena, sizeof(cadena), stdin);
	
	int longitud = strlen(cadena);
	if(cadena[longitud - 1] == '\n'){
		cadena[longitud - 1] = '\0'; // Para eliminar el caracter final de nueva linea
		longitud--;
	}
	
	for(int i = 0; i < longitud; i++){
		cadena[i] += 3;
	}	
	
	printf("\nTu cadena encriptada es %s", cadena);
	
	return 0;
}
