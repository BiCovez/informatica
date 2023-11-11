/*
Ampliar la aplicación anterior, agregando en el hardware, 4 entradas analógicas para
medir 4 temperaturas correspondientes a 4 ambientes de una casa (cocina, living,
dormitorio1, dormitorio2). Guardar en un arreglo de temperaturas. Leer usando
punteros el arreglo de temperaturas cada 10 segundos y mostrarlos en el terminal serie.
*/

#include <LiquidCrystal.h>

const int interruptores[] = {2, 3, 4, 5};
const int luces[] = {6, 7, 8, 9};
const int temperaturas[] = {A0, A1, A2, A3};
char estados[5];
float temp[4];

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(interruptores[i], INPUT);
    pinMode(luces[i], OUTPUT);
    pinMode(temperaturas[i], INPUT);
  }
  
  Serial.begin(9600);
}

void loop() {
  lucesInterruptores();
  temperaturaData();
}

void lucesInterruptores() {
  char *p = estados;
  for (int i = 0; i < 4; i++) {
    estados[i] = digitalRead(interruptores[i]) ? '1' : '0';
    digitalWrite(luces[i], *p == '1' ? HIGH : LOW);
    p++;
  }
  estados[4] = '\0';
}

void temperaturaData() {
  for (int i = 0; i < 4; i++) {
    temp[i] = analogRead(temperaturas[i]) * (5.0 / 1023.0) * 100;
  }
  if (millis() % 10000 < 50) {
    float *t = temp;
    for (int i = 0; i < 4; i++) {
      Serial.print("Temperatura ");
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.println(*t);
      t++;
    }
  }
}
