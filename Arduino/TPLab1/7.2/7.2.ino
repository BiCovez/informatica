/*
Diseñar 2 aplicaciones a elección del alumno, con la placa Arduino, el display LCD y el
circuito.
Controlador de nivel de agua en tanque
*/

#include <LiquidCrystal.h>

const int rs = 8, en = 7, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

int btn1 = 2, btn2 = 3;

int Temp = 25, TempIni = 0;
int Agua = 0;
int Nivel = 0, NivelAnt = 0;

bool Flag;
bool FlagN;
bool FlagC;

long TimeCounter = 0;
long int Timer = 0;
long int Contador = 0;
long int TiempoActual = 0;

const int TimeThreshold = 150;

void setup() {
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2) , SetMode , RISING);
  attachInterrupt(digitalPinToInterrupt(3) , InMode , RISING);

  lcd.begin(16, 2);

  Serial.begin(9600);

  TempIni = Temp;

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
  NivelAgua();
  Temperatura();
  Parpadeo();
}

ISR(TIMER1_COMPA_vect) {
  Timer++;
  if (FlagN) {
    Temp--;
  }
  if (FlagN == 0 && Temp != TempIni) {
    FlagC = 1;
    Temp++;
  }
  if (Flag) {
    Contador++;
    if (Contador > 10) Flag = 0;
  }
}

void NivelAgua() {
  Nivel = map(analogRead(A1), 0, 1023, 0, 100);

  if (Nivel < 10) {
    lcd.setCursor(0, 0);
    lcd.print("Agua =    0" + (String)(Nivel) + "%  ");
  }
  lcd.setCursor(0, 0);
  lcd.print("Agua =    " + (String)(Nivel) + "%  ");

  if (Nivel < 65) {
    lcd.setCursor(0, 0);
    lcd.print("Bomba encendida");
    lcd.setCursor(0, 1);
    lcd.print("Agua =    " + (String)(Nivel) + "%  ");
    delay(500);
    FlagN = 1;
  }
  if (Nivel > 90 && FlagN) {
    lcd.setCursor(0, 0);
    lcd.print("Bomba apagada  ");
    delay(500);
    FlagN = 0;
  }
}

void Temperatura() {
  if (Nivel < 10) {
    lcd.setCursor(0, 1);
    lcd.print("Temp =   0" + (String)(Nivel) + (char)(223) + "C ");
  }
  lcd.setCursor(0, 1);
  lcd.print("Temp =   " + (String)(Temp) + (char)(223) + "C ");

  if (Temp != TempIni && FlagC) {
    lcd.setCursor(0, 0);
    lcd.print("Calentador ON");
    lcd.setCursor(0, 1);
    lcd.print("Temp =   " + (String)(Temp) + (char)(223) + "C ");
    delay(500);
  }
  if (Temp == TempIni && FlagC) {
    lcd.setCursor(0, 0);
    lcd.print("Calentador OFF");
    delay(500);
    FlagC = 0;
  }
}

void SetMode() {
  if (millis() - TimeCounter > TimeThreshold) {
    if (Flag) {
      Contador = 0;
      Temp++;
      TempIni = Temp;
    }
    TimeCounter = millis();
    if (millis() - TiempoActual < 300) {
      Flag = !Flag;
      Temp = Temp - 2;
    }
    TiempoActual = millis();
  }
}

void InMode() {
  if (Flag) {
    if (millis() - TimeCounter > TimeThreshold) {
      Contador = 0;
      Temp--;
      TempIni = Temp;
      TimeCounter = millis();
    }
  }
}

void Parpadeo() {
  if (Flag) {
    if (Timer % 2 == 0) {
      lcd.setCursor(9, 1);
      lcd.print("  ");
      delay(500);
    }
  }
}
