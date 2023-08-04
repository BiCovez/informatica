#include <stdio.h>
#define pi 3.14

/*
	Realizar un programa en C, donde se pida el ingreso del radio y luego se presente
un men� de 3 opciones de c�lculo: (a)-C�lculo de la longitud de la circunferencia,
(b)-C�lculo del �rea del c�rculo y (c)-C�lculo del volumen de la esfera, se pida el
ingreso de la opci�n elegida, se realice el c�lculo correspondiente y se muestre
el resultado. Realizar el programa pero con la instrucci�n switch-case..

*/

int main(){
	float radio, longitud, area, volumen;
	int opcion;
	printf("*************************************************\n");
	printf("************** Opciones de calculo **************\n");
	printf("* 1) Calcular la longitud de la circunsferencia *\n");
	printf("******** 2) Calcular el area del circulo ********\n");
	printf("****** 3) Calcular el volumen de la esfera ******\n");
	printf("*************************************************\n\n");
	
	while (opcion < 1 || opcion > 3){
		printf("Ingrese la opcion para realizar el calculo: ");
		scanf("%d", &opcion);
	}
	
	
	printf("\n\nIngrese el radio: ");
	scanf("%f", &radio);
	
	switch (opcion){
		case 1:
			longitud = 2 * pi * radio;
			printf("\nLa longitud de la circunferencia es de %.2f", longitud);
		break;
		case 2:
			area = pi * radio * radio;
			printf("\nEl area de la circunferencia es de %.2f", area);
		break;
		case 3:
			volumen = 1.33 * pi * radio * radio * radio;
			printf("\nEl volumen de la esfera es de %.2f", volumen);
		break;
	}
	
	return 0;
}


