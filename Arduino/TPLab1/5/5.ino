/*
 Realizar con el Display LCD la aplicación del punto 1){
 Realizar un programa que actúe como contador de 0 a 99, en forma ascendente y
descendente a través de 2 pulsadores. Un pulsador incrementa el contador y el otro 
}
*/

#include <LiquidCrystal.h>

const int rs = 8, en = 2, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

int btn1 = 2, btn2 = 3;
int numeros[] = {0, 0};

long TimeCounter = 0;
long int TiempoActual = 0;

const int TimeThreshold = 75;

void setup() {
  lcd.begin(16,2);
  
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2) , Subir , RISING);
  attachInterrupt(digitalPinToInterrupt(3) , Bajar , RISING);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Contador: ");
  lcd.print(numeros[0]);
  lcd.print(numeros[1]);
}

void Subir() {
  if (millis() > TimeCounter + TimeThreshold) { // if para ejecutar el debounce
    numeros[1]++;
    TimeCounter = millis();

    TiempoActual = millis(); // Se establece el contenido de la variable TiempoActual a millis()
    if (numeros[1] > 9 ) {
      numeros[1] = 0;
      numeros[0]++;
      if (numeros[0] > 9) {
        numeros[0] = 0;
        numeros[1] = 0;
      }
    }
  }
}

void Bajar() {
  if (millis() > TimeCounter + TimeThreshold) {
    numeros[3]--;
    TimeCounter = millis();
    if (numeros[1] < 0 ) {
      numeros[1] = 9;
      numeros[0]--;
      if (numeros[0] < 0) {
        numeros[0] = 9;
        numeros[1] = 9;
      }
    }
  }
}
