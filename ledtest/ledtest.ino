#include <FastLED.h>

#define NUM_LEDS 47
#define LED_PIN 2

CRGB led[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN>(led, NUM_LEDS); 
  FastLED.show();
  
}

void setBlue(int val) {
  for (int i = 0; i < NUM_LEDS; i++){
    led[i] = CRGB(0,255-val,val);  
  }
  FastLED.show();
}
void TurnOnRed(int lednum){
  led[lednum] = CRGB(0,255,0);
  FastLED.show(); 
}
void TurnOffRed(int lednum){
  led[lednum] = CRGB(0,0,0);
  FastLED.show(); 
}
void loop() {
  // put your main code here, to run repeatedly:
  
  for ( int i = 0; i < NUM_LEDS; i++){
    TurnOffRed(i);
    TurnOnRed(i+1);
    TurnOnRed(i+2);
    delay(50);
  }
  for ( int i = NUM_LEDS; i > -1; i--){
    TurnOffRed(i);
    //delay(50);
  }  
  for ( int i = 0; i < NUM_LEDS; i++){
    TurnOnRed(i);
    delay(20);
  }  
  for ( int i = 0; i < 256; i++){
    setBlue(i);
    delay(40);
  }
    for ( int i = 255; i > 0; i--){
    setBlue(i);
    delay(20);
  }
}
