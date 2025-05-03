#include "Pines.h"
#include <QTRSensors.h>

QTRSensors sigueLineas;

const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];
uint16_t umbralValues[SensorCount];
int toleranciaUmbral = 3050;

const int freq = 5000;
const int resolution = 8;


void setup() {
  QTRSetup();
  inicializarMotores();
  while (true) {
    if(digitalRead(BOTON ==1)){
      calibra();
      break;
    }
  }
  while (digitalRead(BOTON) == 0) {
  }
}

void loop() {
  sigueLineas.read(sensorValues);
  // put your main code here, to run repeatedly:
  /*if (sensorValues[1] <= umbralValues[1] && sensorValues[2] <= umbralValues[2]  && sensorValues[5] <= umbralValues[5] && sensorValues[6] <= umbralValues[6]) {
    Motor(50, -50);
  } else if (sensorValues[1] <= umbralValues[1] && sensorValues[2] <= umbralValues[2]  && sensorValues[5] <= umbralValues[5] && sensorValues[6] <= umbralValues[6]) {
    Motor(0, 50);
  }*/if (sensorValues[1] <= umbralValues[1] && sensorValues[2] <= umbralValues[2]  && sensorValues[5] <= umbralValues[5] && sensorValues[6] <= umbralValues[6]) {
    Motor(65, 65);
  }  else if (sensorValues[1] >= umbralValues[1] && sensorValues[2] >= umbralValues[2]  && sensorValues[3] >= umbralValues[3] && sensorValues[4] >= umbralValues[4] &&  sensorValues[5] >= umbralValues[5] && sensorValues[6] >= umbralValues[6]) {
    Motor(100, 100);
    delay (2000);
    
   }
   /*else if (sensorValues[1] <= umbralValues[1] && sensorValues[2] <= umbralValues[2]  && sensorValues[5] <= umbralValues[5] && sensorValues[6] <= umbralValues[6]) {
    Motor(-50, 50);
  }*/ else {
    Motor (0,0);
  }
  for (int i = 0; i <= 7; i++) {
    Serial.print(sensorValues[i]);
    Serial.print(" ");
  }
  Serial.println();
}
