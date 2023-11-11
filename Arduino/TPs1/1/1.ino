

/* 
 *  Realizar un programa que actúe como contador de 0 a 99, en forma ascendente y
descendente a través de 2 pulsadores. Un pulsador incrementa el contador y el otro
decrementa el contador
*/

int btn1 = 2, btn2 = 3; 
int numeros[] = {0, 0, 0, 0}; 
int i = 0; 

long TimeCounter = 0; 
long int TiempoActual = 0; 

const int TimeThreshold = 75; 


void setup(){
  DDRB = B00001111; // Delcaracion de registro para el uso de los segmentos del display
  DDRD = B11110000; // Declaracion de registro para el uso de los segmentos del display
  DDRC = B00001111; // Declaracion de registro para activar las bases de los transistores
  pinMode(btn1, INPUT);  
  pinMode(btn2, INPUT); 
  attachInterrupt(digitalPinToInterrupt(2) , Subir , RISING); 
  attachInterrupt(digitalPinToInterrupt(3) , Bajar , RISING); 
}

void loop(){ 
  for (i = 3; i >= 0; i--){
    contnumeros(numeros[i], i); 
    delay(1); 
  }
}

void Subir(){ 
  if (millis() > TimeCounter + TimeThreshold){ // if para ejecutar el debounce
    numeros[3]++; 
    TimeCounter = millis();
    /*
    if (millis() - TiempoActual < 280){ // Este if es para ejecutar el doble click, que permite reiniciar el contador a 0
      numeros[3] = 0; // Se reinicia a 0 la Unidad
      numeros[2] = 0; // Se reinicia a 0 la Decena
      numeros[1] = 0; // Se reinicia a 0 la Centena
      numeros[0] = 0; // Se reinicia a 0 la unidad de Mil
    }
    */
    
  TiempoActual = millis(); // Se establece el contenido de la variable TiempoActual a millis()
  if (numeros[3] > 9 ){
    numeros[3] = 0;
    numeros[2]++;
    if (numeros[2] > 9){
      numeros[2] = 0;
      numeros[3] = 0;
    }
  }
    
    /*
    if(numeros[3] > 9){ // Este if dice que cuando lo que contiene la unidad sea mayor que 9
      numeros[3] = 0; // Se reinicie el contenido de unidad a 0
      numeros[2]++; // Y que se prenda el display de la decena mostrando un 0
      if(numeros[2] > 9){ // Este if dice que cuando lo que contiene la decena sea mayor que 9
        numeros[2] = 0; // Se reinicie el contenido de decena a 0
        numeros[1]++; // Y que se prenda el display de la centena mostrando un 0
        if(numeros[1] > 9){ // Este if dice que cuando lo que contiene la centena sea mayor que 9
          numeros[1] = 0; // Se reinicie el contenido de centena a 0
          numeros[0]++; // Y que se prenda el display de la unidad de mil mostrando un 0
          if(numeros[0] > 9){ // Este if dice que cuando lo que contiene la unidad de mil sea mayor que 9
            numeros[0] = 0; // Se reinicie el contenido de la unidad de mil a 0
          }
        }
      }
    }
    */
  }
}

void Bajar(){ 
  if (millis() > TimeCounter + TimeThreshold){ 
    numeros[3]--; 
    TimeCounter = millis();
    if (numeros[3] < 0 ){
    numeros[3] = 9;
    numeros[2]--;
      if (numeros[2] < 0){
        numeros[2] = 9;
        numeros[3] = 9;
      }
    }
    
    /*
      if(numeros[3] < 0){ // Este if dice que cuando el contenido de la unidad sea menor a 0
      numeros[3] = 9; // Se establece 9 a la unidad
      numeros[2]--; // Se apaga el display de la decena
      if(numeros[2] < 0){ // Este if dice que cuando el contenido de la decena sea menor a 0
        numeros[2] = 9; // Se establece 9 a la decena
        numeros[1]--; // Se apaga el display de la centena
        if(numeros[1] < 0){ // Este if dice que cuando el contenido de la centena sea menor a 0 
          numeros[1] = 9; // Se establece 9 a la centena
          numeros[0]--; // Se apaga el display de la unidad de mil
          if(numeros[0] < 0){ // Este if dice que cuando el contenido de la unidad de mil sea menor a 0
            numeros[0] = 9; // Se establece 9 a la unidad de mil
          }
        }
      }
    }
    */
  }
}


void contnumeros(int valor,int cfra){ // Este void es donde se guardan las variables que establecen la señales positivas para los transistores y las combinaciones para formar los nuemeros en los displays juntando el puerto B y puerto D
  byte numeroB[] = { B00000011, B00000000, B00000101, B00000100, B00000110, B00000110, B00000111, B00000000, B00000111, B00000110}; // Variable tipo byte que es usada para establecer que leds del 7 segmentos queremos que se prenda, junto con esta parte del puerto B y el puerto D se van a formar los numeros
  byte numeroD[] = { B11110000, B01100000, B10110000, B11110000, B01100000, B11010000, B11010000, B01110000, B11110000, B01110000}; // Este tipo de variables representan un valor de 8 bits
  byte cifra[] = { /* B00010000, B00001000, */ B00000010, B00000001}; // En esta variable que trabaja sobre el puerto C se establecen la señal positiva para los transistores

  PORTB = numeroB[valor]; // Se establece la variable array al puerto B para que cuando sea indicado se prendan los segmentos que se soliciten
  PORTD = numeroD[valor]; // Se establece la variable array al puerto D para que cuando sea indicado se prendan los segmentos que se soliciten
  PORTC = cifra[cfra]; // Se establece la variable array al puerto C para que cuando sea indicado se prenda el transistor que se solicite
}
