#include <Wire.h>
#include "RTClib.h"
#define air1 7
#define air2 8


/*Declare Variables*/
RTC_DS3231 rtc;
const int timer = 3600000; //1 Hour in millseconds

void setup() {
  //Set Time and Date which FIle was compiled -> Loaded on arduino
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(air1, OUTPUT);
  pinMode(air2, OUTPUT);
  delay(3000); // wait for console opening
}

void loop() {

  while(rtc.now().hour() % 3 == 0)
  {
   Serial.println("Pause =================>");
   Serial.println(rtc.now().hour());
   digitalWrite(air1, LOW);
    digitalWrite(air2, LOW);
    delay(timer*2);
  }

  Serial.println("Läuft =================>");
   Serial.println(rtc.now().hour());
    digitalWrite(air1, HIGH);
    digitalWrite(air2, HIGH);
    //delay(timer);

}
