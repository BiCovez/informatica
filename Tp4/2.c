#include <stdio.h>
#include <math.h>

/*
	Realizar un programa donde se ingresen 10 numeros reales a un arreglo y luego se
calcule la suma y el promedio de los elementos de indice par y lo mismo para los
elementos de indice impar

*/

int main(){
	float numeros[10], suma, promedioPar, promedioImpar;
	float sumaPar, sumaImpar;
	int numerosEnteros[10];
	printf("Ingrese 10 numeros para calcular la suma, promedio de los pares e impares\n");
	for(int i = 0; i < 10; i++){
		scanf("%f", &numeros[i]);
		suma += numeros[i];
		
		numerosEnteros[i] = (int)numeros[i];
		if(numerosEnteros[i] % 2 == 0){
			sumaPar += numerosEnteros[i];
		}
		else {
			sumaImpar += numerosEnteros[i];
		}
		
	}
	printf("La suma de todos los numeros ingresados es %.2f\n\n", suma);
	promedioPar = sumaPar / 10;
	printf("El promedio de los numeros pares es de %.2f\n", promedioPar);
	promedioImpar = sumaImpar / 10;
	printf("El promedio de los numeros impares es de %.2f", promedioImpar);
	
	if(sumaPar == 0){
		printf("No se ingresaron numeros pares\n");
	}
	else if(sumaImpar == 0){
		printf("No se ingresaron numeros impares\n");
	}
}
