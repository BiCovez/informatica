/*
Realizar con el Display LCD la aplicación del punto 2)
Realizar un programa que lea la temperatura ambiente a través del sensor LM35 y la
muestre en el display de 2 dígitos de 7 segmentos.
*/
#include <LiquidCrystal.h>
#define sensorTemp A0

float temperatura = 0; 
int numeros[] = {0, 0};

const int rs = 8, en = 2, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

void lecturaSensor(){
  float lectura = analogRead(sensorTemp);
  temperatura = (5 * lectura * 100) / 1024; // Conversion a celcius

  numeros[1] = (int)temperatura / 10; // Decena
  numeros[0] = (int)temperatura % 10; // Unidad
}

void setup(){
  lcd.begin(16, 2);

  Serial.begin(9600);
}

void loop(){
  lecturaSensor();
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: ");
  lcd.print(numeros[0]);
  lcd.print(numeros[1]);  
}
