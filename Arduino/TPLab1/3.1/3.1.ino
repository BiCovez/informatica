/*
  Diseñar 2 aplicaciones con la placa Arduino y el circuito a elección del alumno.
  Sensado de linea blanca con Cny70
*/

int sensor = 2, valorCny70 = 0, led = 3;

void setup() {
  Serial.begin(9600);
  
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  
  digitalWrite(led, LOW);
}

void loop() {
  valorCny70 = digitalRead(sensor); 
  delay(100);
  if (valorCny70 == 0) 
  {
    Serial.println("Linea negra");
    digitalWrite(led, HIGH);
  }
  else
  {
    Serial.println("linea blanca");
    digitalWrite(led, LOW); 
  }
}
