/*
  Realizar un programa que muestre en el display LCD un cronómetro de horas,
  minutos, segundos, decimas de segundo. El conteo de tiempo se inicia y se
  detiene con un pulsador y se pone a cero a través del otro pulsador.
*/

#include <LiquidCrystal.h>

const int rs = 8, en = 2, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

int btn1 = 2, btn2 = 3;
int Seg = 0, Min = 0, Hor = 0;
int contador = 0;
bool flag = false;

long TimeCounter = 0;
long int TiempoActual = 0;

const int TimeThreshold = 150;

void setup() {
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), encendido, RISING);
  attachInterrupt(digitalPinToInterrupt(3), reinicio, RISING);

  lcd.begin(16, 2);

  Serial.begin(9600);

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
  hora();
}

ISR(TIMER1_COMPA_vect) {
  contador++;
  if (flag == 1) Seg++;
}

void encendido() {
  if (millis() - TimeCounter > TimeThreshold) {
    flag = !flag;
    TimeCounter = millis();
  }
}

void reinicio(){
  if (millis() - TimeCounter > TimeThreshold) {
    flag = false;
    Seg = 00;
    Min = 00;
    Hor = 00;
    TimeCounter = millis();
  }
}

void hora() {
  if (Seg > 59) {
    Seg = 00;
    Min++;
    if (Min > 59) {
      Min = 00;
      Hor++;
      if (Hor > 23) {
        Hor = 00;
      }
    }
  }

  if (Seg < 10) { // Estos ifs else son para que no se sobre escriba mal los numeros
    lcd.setCursor(5, 0);
    lcd.print(":0" + (String)(Seg));
  }
  else {
    lcd.setCursor(5, 0);
    lcd.print(":" + (String)(Seg));
  }
  if (Min < 10) {
    lcd.setCursor(2, 0);
    lcd.print(":0" + (String)(Min));
  }
  else {
    lcd.setCursor(2, 0);
    lcd.print(":" + (String)(Min));
  }
  if (Hor < 10) {
    lcd.setCursor(0, 0);
    lcd.print("0" + (String)(Hor));
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print((String)(Hor));
  }
}
