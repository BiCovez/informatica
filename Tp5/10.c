#include <stdio.h>

/*
     Crear una función que devuelva el número de día del año, ingresando como
argumentos, el día, mes y año de la fecha.
*/

int calculoDia(int dia, int mes, int año){ 
    int diaDeMeses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int diaActual;

    if((año % 4 == 0 && año % 100 != 0) || (año % 400 == 0)){
        diaDeMeses[1] = 29;
    }

    for(int i = 1; i < mes; i++){
        diaActual += diaDeMeses[i - 1];
    }

    return diaActual + dia;
}

int main(){
    int dia, mes, año, diaDelAño;

    printf("Ingresa el numero del dia: ");
    scanf("%d", &dia);  

    printf("\nIngresa el numero del mes: ");
    scanf("%d", &mes);

    printf("\nIngresa el numero de año: ");
    scanf("%d", &año);

    if(dia < 0 || dia > 31){
        printf("\nDia invalido, ingresalo nuevamente: ");
        scanf("%d", &dia);
    }
    if(mes < 0 || mes > 12){
        printf("\nMes invalido, ingresalo nuevamente: ");
        scanf("%d", &mes);
    }
    if(año < 0){
        printf("\nAño invalido, ingresalo nuevamente: ");
        scanf("%d", &año);
    }

    diaDelAño = calculoDia(dia, mes, año);

    printf("\nEstas en el dia %d del año", diaDelAño);

    return 0;
}