/*
Realizar un programa que muestre en el display LCD, las raíces de la ecuación
cuadrática X1 y X2, a partir del ingreso de los coeficientes de la ecuación a través
del terminal serie.
*/

#include <LiquidCrystal.h>

const int rs = 8, en = 2, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

float a, b, c;

void setup(){
  lcd.begin(16, 2);
  
  Serial.begin(9600);
}

void loop(){
  Serial.println("Ingrese los coeficientes de a, b y c separados por comas: ");
  if (Serial.available()) {
    a = Serial.parseFloat();
    b = Serial.parseFloat(); 
    c = Serial.parseFloat(); 

    float d = b * b - 4 * a * c; 

    if (d >= 0) {
      float x1 = (-b + sqrt(d)) / (2 * a);
      float x2 = (-b - sqrt(d)) / (2 * a);

      lcd.setCursor(0, 0);
      lcd.print("x1 = ");
      lcd.print(x1);
      
      lcd.setCursor(0, 1);
      lcd.print("x2 = ");
      lcd.print(x2);
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Error: raices");
      
      lcd.setCursor(0, 1);
      lcd.print("complejas");
    }
  }
}
