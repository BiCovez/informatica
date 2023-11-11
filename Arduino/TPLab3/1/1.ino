/*
Agregar 4 interruptores en entradas de la placa Arduino que indiquen el estado de
encendido o apagado de luces de 4 ambientes de una casa y agregar 4 salidas para
controlar las lámparas de iluminación. Utilizando cadenas y punteros, guardar el estado
de las entradas en una cadena de 4 caracteres donde el carácter ‘1’ representa
encendido y el carácter ‘0’ representa apagado. Leer cada carácter a través de punteros
y activar las salidas.
*/

const int interruptores[] = {2, 3, 4, 5};
const int luces[] = {6, 7, 8, 9}; 
char estados[5]; 

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(interruptores[i], INPUT);
    pinMode(luces[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    estados[i] = digitalRead(interruptores[i]) ? '1' : '0'; 
  }
  estados[4] = '\0'; 
  
  char *p = estados; 
  for (int i = 0; i < 4; i++) {
    digitalWrite(luces[i], *p == '1' ? HIGH : LOW); 
    p++; 
  }
}
