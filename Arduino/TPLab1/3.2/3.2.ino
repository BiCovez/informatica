/*
Diseñar 2 aplicaciones con la placa Arduino y el circuito a elección del alumno.
Emisor de caracteres con RF
*/

#include <VirtualWire.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Emisor RF");
  // Se inicializa el RF
  vw_setup(2000); // velocidad: Bits por segundo
  vw_set_tx_pin(2); //Pin 2 como salida para el RF
}
void loop() {
  while (Serial.available() > 0) {
    char dato[1];
    dato[0] = Serial.read();

    //Envía el caracter recibido al RF
    vw_send((uint8_t*)dato, sizeof(dato));
    vw_wait_tx();
  }
  delay(200);
}
