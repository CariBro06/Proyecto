#include <Arduino.h>

#define infrarrojo 14
volatile int contador = 0;
unsigned long lastTime = 0;
const int intervalo = 1000;

void IRAM_ATTR onPulse(){
  contador ++;
}

void setup (){
  Serial.begin(115200);
  pinMode (infrarrojo, INPUT);
  attachInterrupt(digitalPinToInterrupt(infrarrojo), onPulse, FALLING);

}

void loop (){
  unsigned long currentTime = millis();
  if (currentTime - lastTime >= intervalo){
    int rpm = (contador * 60) / (intervalo / 1000);
    Serial.print ("RPM: ");
    Serial.println (rpm);
    contador = 0;
    lastTime = currentTime;
  }
}

//Para esto hay que tener instalada la placa ESP32 en el IDE de Arduino. 
//(Arduino Core for ESP32.