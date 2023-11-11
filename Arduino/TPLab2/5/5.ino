/*
Realizar un programa donde se ingresen por terminal serie los valores de las
coordenadas polares (módulo y ángulo) y se muestren en el display LCD el valor
de la coordenada X y de la coordenada Y
*/

#include <LiquidCrystal.h>

const int rs = 8, en = 2, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Ingrese las coordenadas polares separadas por una coma: ");
  if (Serial.available() > 0) {
    String moduloStr = Serial.readStringUntil(',');
    String anguloStr = Serial.readStringUntil('\n');
    float modulo = moduloStr.toFloat();
    float angulo = anguloStr.toFloat();

    float x = modulo * cos(angulo * PI / 180);
    float y = modulo * sin(angulo * PI / 180);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("X: ");
    lcd.print(x);
    
    lcd.setCursor(0, 1);
    lcd.print("Y: ");
    lcd.print(y);
  }
}
