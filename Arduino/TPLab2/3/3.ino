/*
Realizar un programa que muestre el texto “Universidad Tecnológica Nacional –
Facultad Regional San Francisco” en la primera línea del display LCD
desplazándose horizontalmente. Cuando termina de mostrar el texto lo inicia
nuevamente.
*/

#include <LiquidCrystal.h>

const int rs = 8, en = 2, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String texto = "Universidad Tecnologica Nacional - Facultad Regional San Francisco";
int posicion = 0;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  for (int i = 0; i < 16; i++) {
    lcd.setCursor(i, 0);
    lcd.print(texto.charAt((posicion + i) % texto.length()));
  }
  delay(250);
  posicion++;
  if (posicion >= texto.length()) {
    posicion = 0;
  }
}
