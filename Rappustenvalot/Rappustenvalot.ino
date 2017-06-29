#include <FastLED.h>

#define NUM_LEDS 47
#define LED_PIN 3
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
    
CRGB led[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN>(led, NUM_LEDS); 
  FastLED.show();
  pinMode(inputPin, INPUT);     // declare sensor as input
  Serial.begin(9600);
}

void TurnOnRed(int lednum){
  led[lednum] = CRGB(0,255,0);
  FastLED.show(); 
}
void TurnOff(int lednum){
  led[lednum] = CRGB(0,0,0);
  FastLED.show(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    if (pirState == LOW) {
      // we have just turned on
      for ( int i = 0; i < NUM_LEDS; i++){
        TurnOnRed(i);
      }  
      Serial.println("Motion detected!");     
      pirState = HIGH;
    }
  }else { 
      if (pirState == HIGH){
        // we have just turned off
        Serial.println("Motion ended!");
        for ( int i = 0; i < NUM_LEDS; i++){
          TurnOff(i);
        }  
        // We only want to print on the output change, not state
        pirState = LOW;
    }
  }
}
