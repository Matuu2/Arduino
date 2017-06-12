#include "SevSeg.h"
#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to

SevSeg sevseg; //Initiate a seven segment controller object

#define DHTTYPE DHT22  // DHT 11 (DHT 22 is that better sensor)
DHT dht(DHTPIN, DHTTYPE);

long int number = 1337;
const long interval = 3000;
unsigned long previousMillis = 0;
bool temperaturemeasured = false; 

void setup() {

  byte numDigits = 4;
  byte digitPins[] = {1, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);  

}

void loop() {


  unsigned long currentMillis = millis();
  sevseg.setNumber(number,2);
  sevseg.refreshDisplay(); // Must run repeatedly
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    // Read temperature as Celsius (the default)
    if ( temperaturemeasured ){
    float t = dht.readHumidity() * 100;
    number = (int) t;
    temperaturemeasured = false;     
    }else{
    float t = dht.readTemperature() * 100;
    number = (int) t;
    temperaturemeasured = true;   
    }
    
  }  

}
