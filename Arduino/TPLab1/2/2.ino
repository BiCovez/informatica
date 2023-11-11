/*
Realizar un programa que lea la temperatura ambiente a través del sensor LM35 y la
muestre en el display de 2 dígitos de 7 segmentos.
*/
#define sensorTemp A0
float temperatura = 0; 
int numeros[] = {0, 0, 0, 0};

void lecturaSensor(){
  float lectura = analogRead(sensorTemp);
  temperatura = (5 * lectura * 100) / 1024; // Conversion a celcius

  numeros[3] = (int)temperatura / 10; // Decena
  numeros[2] = (int)temperatura % 10; // Unidad
}

void controladorDigitos(int valor, int cfra) { // Este void es donde se guardan las variables que establecen la señales positivas para los transistores y las combinaciones para formar los nuemeros en los displays juntando el puerto B y puerto D
  byte numeroB[] = { B00000011, B00000000, B00000101, B00000100, B00000110, B00000110, B00000111, B00000000, B00000111, B00000110}; // Variable tipo byte que es usada para establecer que leds del 7 segmentos queremos que se prenda, junto con esta parte del puerto B y el puerto D se van a formar los numeros
  byte numeroD[] = { B11110000, B01100000, B10110000, B11110000, B01100000, B11010000, B11010000, B01110000, B11110000, B01110000}; // Este tipo de variables representan un valor de 8 bits
  byte cifra[] = { /* B00010000, B00001000, */ B00000010, B00000001}; // En esta variable que trabaja sobre el puerto C se establecen la señal positiva para los transistores

  PORTB = numeroB[valor]; // Se establece la variable array al puerto B para que cuando sea indicado se prendan los segmentos que se soliciten
  PORTD = numeroD[valor]; // Se establece la variable array al puerto D para que cuando sea indicado se prendan los segmentos que se soliciten
  PORTC = cifra[cfra]; // Se establece la variable array al puerto C para que cuando sea indicado se prenda el transistor que se solicite
}

void setup(){
  DDRB = B00001111; // Delcaracion de registro para el uso de los segmentos del display
  DDRD = B11110000; // Declaracion de registro para el uso de los segmentos del display
  DDRC = B00001111; // Declaracion de registro para activar las bases de los transistores

  Serial.begin(9600);
}

void loop(){
  lecturaSensor();
  for(int i = 3; i >= 0; i--){
    controladorDigitos(numeros[i], i);
    delay(1);
  }
}
