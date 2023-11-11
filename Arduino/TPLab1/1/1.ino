/*
    Realizar un programa que actúe como contador de 0 a 99, en forma ascendente y
  descendente a través de 2 pulsadores. Un pulsador incrementa el contador y el otro
  decrementa el contador
*/

int btn1 = 2, btn2 = 3;
int numeros[] = {0, 0, 0, 0};
int i = 0;

long TimeCounter = 0;
long int TiempoActual = 0;

const int TimeThreshold = 75;


void setup() {
  DDRB = B00001111; // Delcaracion de registro para el uso de los segmentos del display
  DDRD = B11110000; // Declaracion de registro para el uso de los segmentos del display
  DDRC = B00001111; // Declaracion de registro para activar las bases de los transistores
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2) , Subir , RISING);
  attachInterrupt(digitalPinToInterrupt(3) , Bajar , RISING);
}

void loop() {
  for (i = 3; i >= 0; i--) {
    contnumeros(numeros[i], i);
    delay(1);
  }
}

void Subir() {
  if (millis() > TimeCounter + TimeThreshold) { // if para ejecutar el debounce
    numeros[3]++;
    TimeCounter = millis();

    TiempoActual = millis(); // Se establece el contenido de la variable TiempoActual a millis()
    if (numeros[3] > 9 ) {
      numeros[3] = 0;
      numeros[2]++;
      if (numeros[2] > 9) {
        numeros[2] = 0;
        numeros[3] = 0;
      }
    }
  }
}

void Bajar() {
  if (millis() > TimeCounter + TimeThreshold) {
    numeros[3]--;
    TimeCounter = millis();
    if (numeros[3] < 0 ) {
      numeros[3] = 9;
      numeros[2]--;
      if (numeros[2] < 0) {
        numeros[2] = 9;
        numeros[3] = 9;
      }
    }
  }
}


void contnumeros(int valor, int cfra) { // Este void es donde se guardan las variables que establecen la señales positivas para los transistores y las combinaciones para formar los nuemeros en los displays juntando el puerto B y puerto D
  byte numeroB[] = { B00000011, B00000000, B00000101, B00000100, B00000110, B00000110, B00000111, B00000000, B00000111, B00000110}; // Variable tipo byte que es usada para establecer que leds del 7 segmentos queremos que se prenda, junto con esta parte del puerto B y el puerto D se van a formar los numeros
  byte numeroD[] = { B11110000, B01100000, B10110000, B11110000, B01100000, B11010000, B11010000, B01110000, B11110000, B01110000}; // Este tipo de variables representan un valor de 8 bits
  byte cifra[] = { /* B00010000, B00001000, */ B00000010, B00000001}; // En esta variable que trabaja sobre el puerto C se establecen la señal positiva para los transistores

  PORTB = numeroB[valor]; // Se establece la variable array al puerto B para que cuando sea indicado se prendan los segmentos que se soliciten
  PORTD = numeroD[valor]; // Se establece la variable array al puerto D para que cuando sea indicado se prendan los segmentos que se soliciten
  PORTC = cifra[cfra]; // Se establece la variable array al puerto C para que cuando sea indicado se prenda el transistor que se solicite
}
