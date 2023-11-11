/*
Realizar un programa donde se ingresen por terminal serie los valores de las
coordenadas rectangulares y se muestren en el display LCD el valor del módulo
y el ángulo en coordenadas polares
*/

#include <LiquidCrystal.h>

const int rs = 8, en = 2, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Ingrese las coordenadas rectangulares separadas por una coma: ");
  if (Serial.available() > 0) {
    String xStr = Serial.readStringUntil(',');
    String yStr = Serial.readStringUntil('\n');
    float x = xStr.toFloat();
    float y = yStr.toFloat();

    float modulo = sqrt(x * x + y * y);
    float angulo = atan2(y, x) * 180 / PI;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Modulo: ");
    lcd.print(modulo);
    
    lcd.setCursor(0, 1);
    lcd.print("Angulo: ");
    lcd.print(angulo);
  }
}
