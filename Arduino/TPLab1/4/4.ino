/*
Utilizar un Display LCD de 2 líneas por 16 caracteres. Mostrar el texto en 2 líneas:
“Ingeniería Electrónica” 
*/

#include <LiquidCrystal.h>

const int rs = 8, en = 2, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

void setup(){
  lcd.begin(16, 2);
}

void loop(){
  lcd.setCursor(0,0);
  lcd.print("Ingenieria");

  lcd.setCursor(0,1);
  lcd.print("Electronica");
}
