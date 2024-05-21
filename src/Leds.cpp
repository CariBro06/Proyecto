#include <Adafruit_NeoPixel.h>
#define leds 8
#define pinleds 13
Adafruit_NeoPixel tiraled = Adafruit_NeoPixel (leds, pinleds, NEO_RGB + NEO_KHZ800);

void setup(){
	tiraled.begin ();
}

void loop(){
	for(int i=0;i<=8;i++){
  //tiraled.setPixelColor(i,random(0,255),random(0,255),random(0,255));
  tiraled.setPixelColor(i,255,255,0);//El máximo es 255 de intensidad
  tiraled.show();
  }
}