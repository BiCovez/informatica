#include <stdio.h>

// Hacer un programa en C que lea 10 números enteros y determine la
// cantidad de ellos que son divisibles por 3.

int main(){
	int numerosIngresados[10];
	
	printf("Ingrese 10 numeros para calcular cuales son divisibles por 3: \n");
	for(int i = 0; i < 10; i++){
		scanf("%d", &numerosIngresados[i]);
	}
	for(int i = 0; i < 10; i++){
		if(numerosIngresados[i] % 3 == 0){
			printf("El numero %d es divisible por 3\n", numerosIngresados[i]);
		}
	}
	
	return 0;
}

