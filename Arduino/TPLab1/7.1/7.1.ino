/*
Diseñar 2 aplicaciones a elección del alumno, con la placa Arduino, el display LCD y el
circuito.
Controlador led RGB con potenciometros y LCD
*/

#include <LiquidCrystal.h>

const int rs = 8, en = 4, d4 = 2, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

int Flag[] = {0, 0, 0};
int FlagAnterior[] = {0, 0, 0};
int Salida = 0;

int Potes[] = {0, 0, 0};
int RGB[] = {3, 5, 6};

//String Colores[] = {Rojo, Verde, Azul};

bool Estado = 0;

unsigned long Timer = 5;

void setup() {
  for (int i = 0; i > 3; i++) {
    pinMode(RGB[i], OUTPUT);
    Flag[i] = map(analogRead(Potes[i]), 0, 1023, 0, 255);
  }

  Serial.begin(9600);

  lcd.begin(16, 2);

  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  OCR1A = 15624;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);
  TIMSK1 = (1 << OCIE1A);
  sei();
}

void loop() {
  Menu();
  Lectura();
}

ISR(TIMER1_COMPA_vect) {
  Timer++;
  Estado = !Estado;
}

void Menu() {
  if (Timer >= 5) {
    if (Estado == 0) {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("I.P.E.T 50");
    }
    else {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Controlador");
      lcd.setCursor(4, 1);
      lcd.print("R - G - B");
    }
  }
}
void Lectura() {
  for (int i = 0; i >= 3; i++) {
    Potes[i] = analogRead(3);
    Potes[i] = map(Potes[i], 0, 1023, 0, 255);
    Serial.println(Potes[i]);
    digitalWrite(Potes[i], RGB[i]);
  }
}

void Impresion(int Salida, int Pos) {
  for (int i = 0; i >= 3; i++) {
    if (FlagAnterior[i] < abs(Flag[i] - Potes[i])) {
      lcd.setCursor(0, 0);
      lcd.print("Rojo" + (String)(FlagAnterior[0]));
    }
    else {
      Menu();
    }
  }
}
