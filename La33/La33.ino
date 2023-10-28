#include <DFRobot_SIM808.h>
#include <SoftwareSerial.h>

#define MESSAGE_LENGTH 160
char emergencyMessage[] = "PV=nRT";
String positionMessage;

SoftwareSerial simSerial(2, 3);
DFRobot_SIM808 sim808(&simSerial);

// FUNCIONES, CLASES Y OBJETOS

void inicializacion() {
  int trys = 0;
  while (!sim808.init()) {
    Serial.print("Init error\r\n");
    delay(1000);
    trys++;
    if (trys > 10) { // Manejo de error
      Serial.println("No se pudo inicializar la sim despues de 10 intentos");
      return;
    }
  }
  delay(3000);
  Serial.println("Init success");

  // A PROBAR *************************************************

  if (sim808.attachGPS()) {
    Serial.println("Open the GPS power success");
  }
  else {
    Serial.println("Open the GPS power error");
  }

  // *********************************************************
}

// **************** SIM ***********************+

class getSms {
  private:
    char message[MESSAGE_LENGTH], fullMessage[MESSAGE_LENGTH], phone[16], datetime[24];

    int messageIndex = 0;

  public:
    void messageFilter() {
      if (strcmp(message, emergencyMessage) == 0) {
        Serial.print("\nFrom owner number: ");
        Serial.println(phone);
        printOrder();

        sim808.sendSMS(phone, positionMessage.c_str());
      }
      else {
        Serial.print("\nFrom unknown number: ");
        Serial.println(phone);
        printOrder();
      }
    }

    void messageUnread() {
      messageIndex = sim808.isSMSunread();
      //Serial.print("messageIndex: ");
      //Serial.println(messageIndex);

      if (messageIndex > 0) {
        bool success = sim808.readSMS(messageIndex, message, MESSAGE_LENGTH, phone, datetime);

        if (!success) {
          Serial.println("No se pudo leer el sms");
          return;
        }
        
        strcpy(fullMessage, message);

        message[strlen(emergencyMessage)] = '\0';

        sim808.deleteSMS(messageIndex);
        messageFilter();
      }
    }

    void printOrder() {
      Serial.print("Datetime: ");
      Serial.println(datetime);
      Serial.print("Recieved message: ");
      Serial.println(fullMessage);
    }
};

getSms smsSim; // Objeto

// ************** GPS ********************
// A PROBAR

class getGps {
  private:
    String gpsLatitude, gpsLongitude, gpsAltitude, positionForMaps, address;

  public:
    void getSimPosition() {
      if (sim808.getGPS()) {

        gpsLatitude = sim808.GPSdata.lat;
        gpsLongitude = sim808.GPSdata.lon;
        gpsAltitude = sim808.GPSdata.altitude;

        positionMessage = "Latitud: " + gpsLatitude + ", Longitud: " + gpsLongitude + ", Altitud: " + gpsAltitude;
        positionForMaps = "Latitud: " + gpsLatitude + ", Longitud: " + gpsLongitude;

        Serial.print(positionForMaps);

        sim808.detachGPS();
      }
      else {
        Serial.println("getGPS no funciona");
        return;
      }

    }
    void getSimAddress() {
      if (Serial.available() > 0) {
        if (Serial.readString() == "True") {
          address = Serial.readString();
        }
      }
      return address;
    }
};

getGps gpsSim ; // Objeto

// ***************************************

void setup() {
  simSerial.begin(9600);
  Serial.begin(9600);

  inicializacion();
}

void loop() {
  smsSim.messageUnread();

  gpsSim.getSimPosition();
  //gpsSim.getSimAddress();
}
