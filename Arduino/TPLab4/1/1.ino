/*
Realizar una aplicación en la plataforma Arduino, utilizando Estructuras en el software,
donde se cree un hardware que utilice las entradas analógicas para medir 4
temperaturas correspondientes a 4 ambientes de una casa (cocina, living, dormitorio1,
dormitorio2). Leer a través del puerto serie estas temperaturas cada 10 segundos y
mostrarlos en el terminal serie
*/

struct Ambiente {
  int pin;
  float temperatura;
};

Ambiente ambientes[] = {
  {A0, 0},
  {A1, 0},
  {A2, 0},
  {A3, 0}
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    ambientes[i].temperatura = analogRead(ambientes[i].pin) * (5.0 / 1023.0) * 100;
  }

  if (millis() % 10000 < 50) {
    for (int i = 0; i < 4; i++) {
      Serial.print("Temperatura ");
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.println(ambientes[i].temperatura);
    }
  }
}
