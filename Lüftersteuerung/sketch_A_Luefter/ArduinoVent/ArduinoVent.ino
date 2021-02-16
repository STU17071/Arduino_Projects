#include <Wire.h>
#include "RTClib.h"
#define air1 7
#define air2 8


/*Declare Variables*/
RTC_DS3231 rtc;
const int timer = 3600000; //1 Hour in millseconds

void setup() {
  //Set Time and Date when File was compiled -> Loaded on arduino
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(air1, OUTPUT);
  pinMode(air2, OUTPUT);
  delay(3000); // wait for console opening
}

void loop() {
  if(rtc.now().hour() % 3 == 0)
  {
    int timeend = rtc.now().hour() + 2;
    while (rtc.now().hour() < timeend )
    {
      digitalWrite(air1, HIGH);
      digitalWrite(air2, HIGH);
    }

  }
  else
  {
    digitalWrite(air1, LOW);
    digitalWrite(air2, LOW);
  }
}


//Alter Code
/*
int timeend = rtc.now().hour() + 2;
  while (rtc.now().hour() % 3 == 0 && rtc.now().hour() <= timeend)
  {
    Serial.println("Pause =================>");
    Serial.println(rtc.now().hour());
    digitalWrite(air1, LOW);
    digitalWrite(air2, LOW);

  }

  Serial.println("Läuft =================>");
  Serial.println(rtc.now().hour());
  digitalWrite(air1, HIGH);
  digitalWrite(air2, HIGH);
  //delay(timer);

*/
