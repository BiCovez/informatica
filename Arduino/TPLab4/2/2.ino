/*
Agregar 4 interruptores en entradas de la placa Arduino que indiquen el estado de
encendido o apagado de luces de los ambientes anteriores y agregar 4 salidas para
controlar las lámparas de iluminación. Utilizar en el software Estructuras ampliando la
estructura anterior. Mostrar los miembros de la estructura a través del puerto serie
estas temperaturas cada 10 segundos y mostrarlos en el terminal serie.
*/

struct Ambiente {
  int pinTemperatura;
  float temperatura;
  int pinInterruptor;
  int pinLuz;
};

Ambiente ambientes[] = {
  {A0, 0, 2, 6},
  {A1, 0, 3, 7},
  {A2, 0, 4, 8},
  {A3, 0, 5, 9}
};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(ambientes[i].pinInterruptor, INPUT);
    pinMode(ambientes[i].pinLuz, OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    ambientes[i].temperatura = analogRead(ambientes[i].pinTemperatura) * (5.0 / 1023.0) * 100;
    if (digitalRead(ambientes[i].pinInterruptor)) {
      digitalWrite(ambientes[i].pinLuz, HIGH);
    } else {
      digitalWrite(ambientes[i].pinLuz, LOW);
    }
  }

  if (millis() % 10000 < 50) {
    for (int i = 0; i < 4; i++) {
      Serial.print("Temperatura ");
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.println(ambientes[i].temperatura);
      Serial.print("Luz ");
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.println(digitalRead(ambientes[i].pinLuz) ? "Encendida" : "Apagada");
    }
  }
}
